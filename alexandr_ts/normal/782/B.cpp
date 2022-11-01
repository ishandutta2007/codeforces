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
const ll INF = 2e12 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

int x[N], v[N];

ld calc(ld m, int n) {
    ld ans = 0;
    fr(i, n)
        ans = max(ans, abs(x[i] - m) / v[i]);
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> x[i];
    fr(i, n)
        cin >> v[i];
    ld l = 0, r = MOD;
    fr(i, 200) {
        ld m1 = (2 * l + r) / 3.;
        ld m2 = (l + 2 * r) / 3.;
        if (calc(m1, n) < calc(m2, n))
            r = m2;
        else
            l = m1;
    }
    cout << fixed << setprecision(12) << calc(l, n);
}