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
        ll a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        ll needa = a/c + (a%c > 0 ? 1 : 0);
        ll needb = b/d + (b%d > 0 ? 1 : 0);
        if(needa + needb <= k){
            cout << needa << " " << needb << endl;
        }else{
            cout << -1 << endl;
        }
    }
}