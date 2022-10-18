#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

const int mod=1e9+7;
void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
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
const int g=1e6+5;
vector<int> fra;
void init(){
    fra.resize(g);
    fra[0]=1;
    for(int i=1;i<g;i++){
        fra[i]=mul(fra[i-1],i);
    }
}
int C(int n,int k){
    if(n<0 || k<0 || n<k){
        return 0;
    }
    return mul(fra[n],mul(inv(fra[k]),inv(fra[n-k])));
}
int main(){
	AquA;
    init();
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        if(n==m){
            cout << mul(k,m) << "\n";
            continue;
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            add(ans,mul(i,mul(C(n-i-1,m-i),inv(po(2,n-i)))));
        }
        cout << mul(ans,k) << "\n";
    }
	return 0;
}