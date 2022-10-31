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
main(){
    FAST;
    ll q;
    cin >> q;
    while(q--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll fc = min(a, b/2); //2
        ll sc = min(b, c/2); //2
        ll fsc = fc + min(b-fc*2, c/2);
        ll sfc = sc + min((b-sc)/2, a);
        cout << max(fsc, sfc)*3 << endl;
    }
}