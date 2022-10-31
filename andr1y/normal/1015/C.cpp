#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
ll a[N], b[N], d[N];
main(){
    FAST;
    ll n, m;
    cin >> n >> m;
    for(ll i = 0;i<n;i++){
        cin >> a[i] >> b[i];
        d[i] = a[i]-b[i];
    }
    sort(d, d+n, greater<ll>());
    ll ns = 0;
    for(ll i = 0;i<n;i++) ns+=a[i];
    ll dm = 0;
    while(ns > m && dm < n){
        ns-=d[dm++];
    }
    if(ns > m) cout << -1;
    else cout << dm;
}