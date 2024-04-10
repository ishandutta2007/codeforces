#include <bits/stdc++.h>
/// 500 485 462 A4
/// yani mishe?
using namespace std;
typedef long long int ll;
typedef complex<double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=520;
ll n,m,k;
vector <pair <int,pii> > g[N][N];
ll dp[N][N][12];
int Main(){
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        for (int j=2;j<=m;j++){
            ll x;
            cin >> x;
            g[i][j-1].pb({x,{i,j}});
            g[i][j].pb({x,{i,j-1}});
        }
    }
    for (int i=2;i<=n;i++){
        for (int j=1;j<=m;j++){
            ll x;
            cin >> x;
            g[i-1][j].pb({x,{i,j}});
            g[i][j].pb({x,{i-1,j}});
        }
    }
    if (k%2==1){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cout << -1 << " ";
            }
            cout << endl;
        }
        return 0;
    }
    memset(dp,63,sizeof dp);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) dp[i][j][0]=0;
    }
    for (int i=1;i<=k/2;i++){
        for (int x=1;x<=n;x++){
            for (int y=1;y<=m;y++){
                for (auto U : g[x][y]){
                    dp[x][y][i]=min(dp[x][y][i],dp[U.S.F][U.S.S][i-1]+U.F*2);
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout << dp[i][j][k/2] << " ";
        }
        cout << endl;
    }
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    //cin >> t;
    while(t--){
        Main();
    }
}