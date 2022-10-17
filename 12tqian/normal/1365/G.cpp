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

ll ask(vi v) {
    if (sz(v) == 0) return 0;
    cout << "? ";
    cout << sz(v) << " ";
    each(e, v) cout << e+1 << " ";
    cout << endl;
    ll x; cin >> x;
    return x;
}

void finish(vl v) {
    cout << "! ";
    each(e, v) cout << e << " ";
    cout << endl;
    exit(0);
}

const int N = 1000;
const int Q = 13;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vi masks;
    f0r(i, (1 << Q)) {
        if (__builtin_popcount(i) == Q / 2) {
            masks.pb(i);
        }
    }
    vl queries(Q);
    f0r(i, Q) {
        vi use;
        f0r(j, sz(masks)) {
            if (j < n) {
                if (masks[j] & (1 << i)) {
                    use.pb(j);
                }
            }
        }
        queries[i] = ask(use);
    }
    vl res(n);

    f0r(i, n) {
        f0r(j, Q) {
            if ((masks[i] & (1 << j)) == 0) {
                res[i] |= queries[j];
            }
        }
    }
    finish(res);

    return 0;
}