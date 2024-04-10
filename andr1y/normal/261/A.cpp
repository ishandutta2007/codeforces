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
#define N 100010
#define INF 101111111111111
using namespace std;
ll a[N];
main(){
    FAST;
    ll m, minm = INF;
    cin >> m;
    for(ll i =0;i<m;i++){
        ll ax = 0;
        cin >> ax;
        minm = min(minm, ax);
    }
    ll n;
    cin >> n;
    for(ll i =0;i<n;i++) cin >> a[i];
    sort(a, a+n, greater<ll>());
    ll res = 0;
    for(ll i =0;i<n;i++){
        for(ll j = 0;j<minm && i<n;j++, i++) res+=a[i];
        i++;
    }
    cout << res;
}