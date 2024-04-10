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
const int N=210;
vector <int> b[N];
ll ans[N][N];
int Main(){
    ll n,m;
    cin >> n >> m;
    for (int i=0;i<=max(m,n);i++){
        b[i].clear();
    }
    vector <pii> a;
    for (int i=1;i<=m;i++){
        a.pb({1e9,i});
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<m;j++){
            ll x;
            cin >> x;
            b[i].pb(x);
        }
        sort(b[i].begin(),b[i].end());
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        for (int j=0;j<b[i].size();j++){
            ans[i][a[j].S]=b[i][j];
            a[j].F=min(a[j].F,b[i][j]);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
  //  cout << endl;

    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}