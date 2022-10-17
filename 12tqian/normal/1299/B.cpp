#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define trav(t, a) for (auto& t : a)

#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

template <class T> bool ckmax(T& a, T b) { return a < b ? a = b, 1 : 0; }
template <class T> bool ckmin(T& a, T b) { return a > b ? a = b, 1 : 0; }

int main() {
    cin.tie(0)->sync_with_stdio(0);

    auto fail = []() {
        cout << "NO" << '\n';
        exit(0);
    };

    auto win = []() {
        cout << "YES" << '\n';
        exit(0);
    };

    int n; cin >> n;

    vi x(n), y(n);

    f0r(i, n) cin >> x[i] >> y[i];

    if (n%2 == 1) fail();

    set<pi> vals;

    f0r(i, n) {
        vals.emplace(x[i]+x[(i+n/2)%n], y[i]+y[(i+n/2)%n]);
    }

    if (sz(vals) != 1) fail();
    win();

    return 0;
}