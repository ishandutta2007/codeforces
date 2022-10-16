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
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m));
    f0r(i, n) f0r(j, m) cin >> a[i][j];
    auto calc = [&](vi& x, vi& y) -> int {
        int num = 0;
        f0r(i, m) {
            if (x[i] != y[i]) {
                num++;
            }
        }
        return num;
    };
    auto check = [&](vi v) -> bool {
        f0r(i, n) {
            if (calc(v, a[i]) > 2) return false;
        }
        return true;
    };
    auto fail = [&]() {
        cout << "No" << '\n';
        exit(0);
    };
    auto finish = [&](vi v) {
        assert(check(v));
        cout << "Yes" << '\n';
        each(x, v) cout << x << " ";
        cout << '\n';
        exit(0);
    };
    auto one_diff = [&](vi v, int id) -> pi {
        f0r(i, n) {
            if (calc(v, a[i]) >= 4) {
                return {0, 0};
            } else if (calc(v, a[i]) == 3) {
                v[id] = a[i][id];
                if (check(v)) {
                    return {1, a[i][id]};
                }
                return{0, 0};
            }
        }
        return {1, v[id]};
    };  
    vi v = a[0]; // preliminary check
    if (check(v)) finish(v);
    vi diff(n);
    f0r(i, n) {
        diff[i] = calc(v, a[i]);
        if (diff[i] > 4) fail();
        if (diff[i] == 4) {
            vi loc;
            f0r(j, m) {
                if (a[i][j] != v[j]) {
                    loc.pb(j);
                }
            }
            f0r(msk, (1 << 4)) {
                vi use = v;
                f0r(j, 4) {
                    if ((1 << j) & msk) {
                        use[loc[j]] = a[i][loc[j]];
                    } else {
                        use[loc[j]] = v[loc[j]];
                    }
                }
                if (check(use)) finish(use);
            }
            fail();
        }
    }
    f0r(i, n) {
        if (calc(v, a[i]) == 3) {
            auto& ot = a[i];
            vi loc;
            f0r(j, m) {
                if (ot[j] != v[j]) {
                    loc.pb(j);
                }
            }
            f0r(i1, 3) {
                f0r(i2, 3) {
                    if (i1 == i2) continue;
                    f0r(i3, 3) {
                        if (i3 == i1 || i3 == i2) continue;
                        vi use = v; 
                        use[loc[i2]] = a[i][loc[i2]];
                        auto res = one_diff(use, i3);
                        if (res.f == 1) {
                            use[i3] = res.s;
                            finish(use);
                        }
                    }

                }
            }
            fail();
        }
    }
    assert(false);
    return 0;
}