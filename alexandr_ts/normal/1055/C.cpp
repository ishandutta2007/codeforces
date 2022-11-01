#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int MAX = 1e5 + 1;
const int N = 2e6 + 10;

ll dif(ll la, ll ra, ll ta, ll lb, ll rb, ll tb) {
    ll g = __gcd(ta, tb);
    if (g == 1)
        return 0;
    return ((lb - la) % g + g) % g;
}

int main() {
    //freopen("a.in", "r", stdin);
    ll la, ra, ta, lb, rb, tb;
    cin >> la >> ra >> ta;
    cin >> lb >> rb >> tb;
    //ra++, rb++;
    ll dif1 = dif(la, ra, ta, lb, rb, tb);
    ll dif2 = dif(lb, rb, tb, la, ra, ta);

    ll ans = 0;
    ans = max(ans, min(rb - lb + 1, ra - la + 1 - dif1));
    ans = max(ans, min(ra - la + 1, rb - lb + 1 - dif2));
    cout << ans;
}