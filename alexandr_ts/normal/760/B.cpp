#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const ll INF = 2e9 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

ll sq(ll n) {
    return n * (n + 1) / 2;
}

ll calc(ll mid, ll n, ll k) {
    ll ans = sq(mid) * 2 - mid;
    if (k < mid)
        ans -= sq(mid - k);
    if (k + mid > n + 1)
        ans -= sq(k + mid - n - 1);
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    m -= n;
    ll l = 0, r = m + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (calc(mid, n, k) > m)
            r = mid;
        else
            l = mid;
    }
    cout << l + 1;
}