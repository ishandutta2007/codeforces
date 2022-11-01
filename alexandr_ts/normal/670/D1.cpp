#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 3;
const int INF = 2e9 + 1;

ll a[N], b[N];

bool solve(ll m, ll k, int n) {
    fr(i, n) {
        k -= max(0ll, -b[i] + a[i] * m);
        if (k < 0) return false;
    }
    return true;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];
    fr(i, n)
        cin >> b[i];
    ll l = 0, r = (accumulate(b, b + n, 0ll) + k) / accumulate(a, a + n, 0ll) + 1;
    fr(i, n)
        r = min(r, (k + b[i]) / a[i] + 1);
    while (r - l > 1) {
        //cout << l << " " << r << endl;
        ll m = (l + r) / 2;
        if (solve(m, k, n))
            l = m;
        else
            r = m;
    }
    cout << l;
}