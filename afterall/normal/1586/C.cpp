#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e6+100;
vector <int> a[N];
vector <int> b[N];
ll val[N];
int Main(){
    ll n,m;
    cin >> n >> m;
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=m+1;j++){
            a[i].pb(1e9);
            b[i].pb(0);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;
            cin >> c;
            if (c=='.') b[i][j]=1;
        }
    }
    for (int i=1;i<=m;i++){
        a[1][i]=1;
    }
    for (int i=1;i<=n;i++){
        a[i][1]=1;
    }
    for (int i=2;i<=m;i++){
        for (int j=2;j<=n;j++){
            a[j][i]=i;
        }
    }
    val[1]=1;
    for (int i=2;i<=n;i++){
        for (int j=2;j<=m;j++){
            if (b[i-1][j]==1){
                a[i][j]=min(a[i][j],a[i-1][j]);
            }
            if (b[i][j-1]==1){
                a[i][j]=min(a[i][j],a[i][j-1]);
            }
        }
    }
    for (int i=2;i<=m;i++){
        val[i]=val[i-1];
        for (int j=2;j<=n;j++){
            val[i]=max(val[i],a[j][i]);
        }
    }
    ll q;
    cin >> q;
    while(q--){
        ll l,r;
        cin >> l >> r;
        if (val[r]>l) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
   // cin >> t;
    while(t--) Main();
}
/*
1
1
1
2

2

0

0

4

4

1
*/