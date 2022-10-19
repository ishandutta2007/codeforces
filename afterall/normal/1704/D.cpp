#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define int long long
#define endl '\n'
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=2e5+100;
vector <int> a[N];
ll par[N];
void Main(){
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        par[i]=0;
        for (int j=0;j<m;j++){
            ll x;
            cin >> x;
            a[i].pb(x);
            par[i]+=x*j;
        }
    }
    vector <pii> b;
    for (int i=1;i<=n;i++){
        b.pb({par[i],i});
    }
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    cout << b[0].S << " " << b[0].F-b[1].F << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}