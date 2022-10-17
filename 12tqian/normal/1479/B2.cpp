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
#define sz(x) (int) (x).size()
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

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vi a(n);
    f0r(i, n) cin >> a[i];
    vi b;
    int i1 = 0;
    int i2 = 0;
    while (i1 != n) {
        while (i2 < n-1 && a[i2] == a[i2+1]) i2++;
        b.pb(a[i1]);
        i1 = ++i2;
    }

    int sz = sz(b);

    int ans = sz; // case 1
    vi best(n+1, -1);
    int large = 0;
    f1r(i, 1, sz) {
        int val = max(best[b[i]]+1, large);
        ckmax(best[b[i-1]], val);
        ckmax(large, val);
    }

    int mx = 0;
    each(t, best) ckmax(mx, t);
    ckmin(ans, sz - mx);
    cout << ans << '\n';
    return 0;
}