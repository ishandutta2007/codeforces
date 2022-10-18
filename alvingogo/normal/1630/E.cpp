#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

const int mod=998244353;
void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
    x+=mod*(x<0);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int po(int x,int y){
    int z=1;
    while(y){
        if(y&1){
            z=mul(z,x);
        }
        x=mul(x,x);
        y>>=1;
    }
    return z;
}
int inv(int x){
    return po(x,mod-2);
}
vector<int> fra;
void init(int x){
    fra.resize(x);
    fra[0]=1;
    for(int i=1;i<x;i++){
        fra[i]=mul(i,fra[i-1]);
    }
}
int main(){
    AquA;
    init(1e6+7);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            a--;
            v[a]++;
        }
        vector<int> nw;
        int g=0;
        for(int i=0;i<n;i++){
            if(v[i]){
                nw.push_back(v[i]);
                g=__gcd(g,v[i]);
            }
        }
        if(g==n){
            cout << 1 << "\n";
            continue;
        }
        int all=0;
        vector<int> ak(n+1),bk(n+1);
        for(int i=1;i<=g;i++){
            if(g%i==0){
                int z=fra[n/i];
                for(auto h:nw){
                    z=mul(z,inv(fra[h/i]));
                }
                ak[i]=z;
            }
        }
        for(int i=1;i<=n;i++){
            int z=n/__gcd(n,i);
            if(g%z==0){
                add(all,ak[z]);
            }
        }   
        //cout << all << '\n';
        all=mul(all,inv(n));
        for(int i=1;i<=g;i++){
            if(g%i==0){
                int z=ak[i];
                z=mul(z,inv(mul(n/i,n/i-1)));
                int sum=0,f=0;
                for(auto h:nw){
                    add(sum,mul(2,mul(f,h/i)));
                    add(f,h/i);
                }
                z=mul(z,sum);
                bk[i]=z;
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            int z=n/__gcd(n,i);
            if(g%z==0){
                add(sum,bk[z]);
            }
        }
        cout << mul(sum,inv(all)) << "\n";
    }
    return 0;
}