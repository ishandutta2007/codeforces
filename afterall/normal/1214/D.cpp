#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e6+100;
vector <int> a[N];
vector <int> b[N];
ll t[N];
ll Main(){
    ll n,m;
    cin >> n >> m;
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=m+1;j++){
            a[i].pb(0);
            b[i].pb(0);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;
            cin >> c;
            if (c=='.'){
                a[i][j]=1;
                b[i][j]=1;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (i==1 && j==1) continue;
            a[i][j]=min(a[i][j],max(a[i-1][j],a[i][j-1]));
        }
    }
    if (a[n][m]==0) kill(0);
    for (int i=n;i;i--){
        for (int j=m;j;j--){
            if (i==n && j==m) continue;
            b[i][j]=min(b[i][j],max(b[i+1][j],b[i][j+1]));
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j] && b[i][j]) t[i+j]++;
          //  cout << i << " " << j << endl;
        }
    }
    ll mi=2;
    for (int i=3;i<n+m;i++) mi=min(mi,t[i]);
    cout << mi << endl;
}
int32_t main(){
    ll t;
  //  cin >> t;
  t=1;
    while(t--) Main();
}