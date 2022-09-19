#include <bits/stdc++.h>
/// 500 485 462 A4
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=510;
ll dp[N][N][N];
pii nxt[N][2];
int32_t main(){
    sync;
    ll n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    for (int i=0;i<m;i++){
        string s="";
        for (int j=0;j<i;j++){
            s+=b[j];
        }
        string t=s;
        t+='0';
        string g=s;
        g+=b[i];
        if (t==g && t.size()==m){
            nxt[i][0].S=1;
        }
        while(t!=g || t.size()==m){
            g.pop_back();
            reverse(t.begin(),t.end());
            t.pop_back();
            reverse(t.begin(),t.end());
        }
        nxt[i][0].F=t.size();
    }
    for (int i=0;i<m;i++){
        string s="";
        for (int j=0;j<i;j++){
            s+=b[j];
        }
        string t=s;
        t+='1';
        string g=s;
        g+=b[i];
        if (t==g && t.size()==m){
            nxt[i][1].S=1;
        }
        while(t!=g || t.size()==m){
            g.pop_back();
            reverse(t.begin(),t.end());
            t.pop_back();
            reverse(t.begin(),t.end());
        }
        nxt[i][1].F=t.size();
    }
    memset(dp,63,sizeof dp);
    dp[0][0][0]=0;
    /// i taye aval state j k ta b sakhtim
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            for (int k=0;k<n-m+2;k++){
                if (a[i]=='1'){
                    dp[i+1][nxt[j][0].F][k+nxt[j][0].S]=min(dp[i+1][nxt[j][0].F][k+nxt[j][0].S],dp[i][j][k]+1);
                    dp[i+1][nxt[j][1].F][k+nxt[j][1].S]=min(dp[i+1][nxt[j][1].F][k+nxt[j][1].S],dp[i][j][k]);
                }
                else{
                    dp[i+1][nxt[j][0].F][k+nxt[j][0].S]=min(dp[i+1][nxt[j][0].F][k+nxt[j][0].S],dp[i][j][k]);
                    dp[i+1][nxt[j][1].F][k+nxt[j][1].S]=min(dp[i+1][nxt[j][1].F][k+nxt[j][1].S],dp[i][j][k]+1);
                }
            }
        }
    }
    for (int i=0;i<=n-m+1;i++){
        ll ans=N*2;
        for (int j=0;j<m;j++){
            ans=min(ans,dp[n][j][i]);
        }
        if (ans>n) cout << -1 << " ";
        else cout << ans << " ";
    }
    cout << endl;
}