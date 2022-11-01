#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e15 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

const int N = 1e5 + 10;
const int M = 1e3 + 10;

ll a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    ll n, p;
    cin >> n >> p;
    fr(i, n)
        cin >> a[i] >> b[i];
    ll sum = accumulate(a, a + n, 0ll);
    ll b1 = accumulate(b, b + n, 0ll);
    if (p >= sum) {
        cout << -1;
        return 0;
    }
    //cout << fixed << setprecision(12) << ((ld)b1 / (ld)(sum - p));
    ld l = 0, r = INF;
    fr(i1, 200) {
        ld m = (l + r) / 2.;
        ld suma = 0;
        fr(i, n) {
            suma += max((ld)0, ((ld)a[i] * m - (ld)b[i]) / p);
            if (suma > m + EPS)
                break;
        }
        if (suma < m)
            l = m;
        else
            r = m;
    }
    cout << fixed << setprecision(12) << l;
}