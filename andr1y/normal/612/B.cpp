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
#define N 200005
#define INF 101111111111111
using namespace std;
ll p[N];
main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i = 0, e;i<n;i++){
        cin >> e;
        p[e] = i;
    }
    ll res = 0;
    for(ll i = 2;i<=n;i++) res += abs(p[i] - p[i-1]);
    cout << res;
}