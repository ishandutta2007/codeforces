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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vl a(n);
    vl b(n);
    f0r(i, n) cin >> a[i];
    f0r(i, n) cin >> b[i];
    vl pre(n);
    vl suf(n);
    f0r(i, n) {
        pre[i] = (i ? pre[i - 1] : 0) + a[i] * b[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = (i != n - 1 ? suf[i + 1] : 0) + a[i] * b[i];
    }
    ll ans = pre[n - 1];
    f0r(i, n) { 
        ll cur = 0;
        f1r(len, 1, n) {
            int l = i - (len - 1);
            int r = (i + 1 + (len - 1));
            if (l < 0 || r >= n) break;
            ll res = 0;
            if (l) res += pre[l - 1];
            if (r != n - 1) res += suf[r + 1];
            cur += a[l] * b[r] + a[r] * b[l];
            res += cur;
            ckmax(ans, res);
        }
    }
    f0r(i, n) {
        ll cur = a[i] * b[i];
        f1r(len, 2, n) {
            int l = i - (len - 1);
            int r = i + len - 1;
            if (l < 0 || r >= n) break;
            ll res = 0;
            if (l) res += pre[l - 1];
            if (r != n - 1) res += suf[r + 1];
            cur += a[l] * b[r] + a[r] * b[l];
            res += cur;
            ckmax(ans, res);
        }
    }
    cout << ans << '\n';

    return 0;
}