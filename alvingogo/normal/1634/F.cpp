#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int n,q,mod;
    cin >> n >> q >> mod;
    vector<int> fib(300077);
    fib[1]=fib[2]=1;
    for(int i=3;i<300077;i++){
        fib[i]=(fib[i-1]+fib[i-2])%mod;
    }
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v[i]-=a;
        v[i]=(v[i]+mod)%mod;
    }
    for(int i=n-1;i>=2;i--){
        v[i]=((v[i]-v[i-1]-v[i-2])%mod+mod)%mod;
    }
    if(n>1){
        v[1]=(v[1]-v[0]+mod)%mod;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i]==0){
            cnt++;
        }
    }
    auto upd=[&](int x,int a){
        if(x<0 || x>=n){
            return;
        }
        if(v[x]==0){
            cnt--;
        }   
        v[x]+=a;
        v[x]%=mod;
        v[x]=(v[x]+mod)%mod;
        if(v[x]==0){
            cnt++;
        }
    };
    for(int i=0;i<q;i++){
        char c;
        cin >> c;
        int sign=1;
        if(c=='B'){
            sign=-1;
        }
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        upd(l,sign);
        upd(r+1,-sign*fib[r-l+2]);
        upd(r+2,-sign*fib[r-l+1]);
        if(cnt==n){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}