#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

const int mod=1e9+7;
void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
    x+=mod*(x<0);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
signed main(){
    AquA;
    int t;
    cin >> t;
    vector<int> z(1e6+7),ivz(1e6+7);
    z[0]=1;
    ivz[0]=1;
    for(int i=1;i<1e6+7;i++){
        z[i]=mul(z[i-1],2);
        ivz[i]=mul(ivz[i-1],(mod+1)/2);
    }
    while(t--){
        int n;
        cin >> n;
        if(n==1){
            cout << 1 << "\n";
            continue;
        }
        vector<int> v(n+1),dp(n+1);
        int now=0,zz=n;
        for(int j=n;j>=2;j--){
            int u=(j+1)/2;
            int x=z[n-u];
            if(j==n){
                x=mul(x,2);
            }
            now=mul(now,2);
            while(zz>=2*j){
                add(now,dp[zz]);
                zz--;
            }
            add(x,-mul(now,z[j-u]));
            //cout << now << "\n";
            v[j]=x;
            dp[j]=mul(v[j],ivz[j-u]);
            //dp[j]=mul((now+1)%mod,1);
        }   
        for(int i=1;i<=n;i++){
            //cout << v[i] << "\n";
            cout << mul(v[i],ivz[n]) << "\n";
        }
    }
    return 0;
}