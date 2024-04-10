#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
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
int inv(int x){
    return x==1?1:mul(inv(mod%x),mod-mod/x);
}
vector<int> fra;
void init(int n){
    fra.resize(n);
    fra[0]=1;
    for(int i=1;i<n;i++){
        fra[i]=mul(fra[i-1],i);
    }
}
int conb(int n,int k){
    if(n<0 || k<0 || n<k){
        return 0;
    }
    return mul(fra[n],mul(inv(fra[n-k]),inv(fra[k])));
}
int main(){
    AquA;
    int n;
    cin >> n;
    init(1e6+7);
    int ans=0;
    for(int i=n%2;i<=n;i+=2){
        int u=n-i;
        int h=conb(u-1,i-1)+conb(u,i);
        h%=mod;
        add(ans,mul(h,mul(2,fra[u])));
    }
    cout << ans << "\n";
    return 0;
}