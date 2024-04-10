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
pll a[N];
bool cmp(pll a, pll b){
    return a.x < b.x;
}
main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i=0;i<n;i++) cin >> a[i].x >> a[i].y;
    sort(a, a+n, cmp);
    ll rg = -1, res = 0;
    for(ll i = 0;i<n;i++){
        if(a[i].y <= rg) res++;
        rg = max(rg, a[i].y);
    }
    cout << res;
}