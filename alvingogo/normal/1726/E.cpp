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
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int inv(int x){
    return x==1?1:mul(inv(mod%x),mod-mod/x);
}
vector<int> fra;
void init(int x){
    fra.resize(x);
    fra[0]=1;
    for(int i=1;i<x;i++){
        fra[i]=mul(fra[i-1],i);
    }
}
int main(){
    AquA;
    init(3e5+7);
    vector<int> pre(3e5+7);
    pre[0]=1;
    pre[1]=1;
    for(int i=2;i<3e5+7;i++){
        pre[i]=pre[i-1];
        add(pre[i],mul(i-1,pre[i-2]));
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans=0;
        for(int i=0;i<n;i++){
            if(n-4*i<0){
                break;
            }
            add(ans,mul(pre[n-4*i],mul(fra[n-2*i],mul(inv(fra[i]),inv(fra[n-4*i])))));
        }
        cout << ans << "\n";
    }
    return 0;
}