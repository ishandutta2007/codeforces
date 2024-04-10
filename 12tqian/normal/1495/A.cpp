#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve_case() {
    int n; cin >> n;
    vl x;
    vl y;
    f0r(i, 2 * n) {
        ll X, Y; cin >> X >> Y;
        if (X == 0) x.pb(Y * Y);
        else y.pb(X * X);
    }
    sort(all(x)); sort(all(y));
    long double res = 0;
    f0r(i, n) res += sqrt(x[i] + y[i]);
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(15);
    int tt; cin >> tt;
    while (tt--) solve_case();
    return 0;
}