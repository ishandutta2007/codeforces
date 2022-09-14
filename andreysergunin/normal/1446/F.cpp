#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const ld PI = acosl(-1);

class BIT {
public:
    BIT(int n) {
        arr.resize(n);
    }
    
    void add(int pos, int val) {
        for (int i = pos; i < sz(arr); i |= i + 1) {
            arr[i] += val;
        }
    }

    int sum(int pos) {
        int res = 0;
        for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
            res += arr[i];
        }
        return res;
    }

private:
    vector<int> arr;
};

struct Point {
    ll x, y;
};

ld dist(const Point &a) {
    return hypotl(a.x, a.y);
}

ld norm(ld x) {
    if (x < -PI) {
        x += 2 * PI;
    } else if (x > PI) {
        x -= 2 * PI;
    }
    return x;
}

void solve() { 
    int n;
    ll k;
    cin >> n >> k;

    vector<Point> p(n);
    vector<ld> alpha(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        alpha[i] = atan2l(p[i].y, p[i].x);
    }

    ld lf = 0, rg = 1e5;

    for (int op = 0; op < 100; ++op) {
        ld r = (lf + rg) / 2;

        ll in = 0;
        
        vector<pair<ld, int>> ang;

        for (int i = 0; i < n; ++i) {
            if (dist(p[i]) <= r) {
                ++in;
            } else {
                ld beta = acosl(r / dist(p[i]));
                ang.push_back({norm(alpha[i] + beta), i});
                ang.push_back({norm(alpha[i] - beta), i});
            }
        }

        sort(all(ang));

        vector<int> used(n, -1);
        BIT bit(2 * n);

        int cnt = 0;
        ll res = in * (n - in) + in * (in - 1) / 2;
        for (int j = 0; j < sz(ang); ++j) {
            int i = ang[j].second;
            if (used[i] != -1) {
                ++cnt;
                res += bit.sum(j) - bit.sum(used[i]);
                bit.add(used[i], 1);
            } else {
                res += cnt;
                used[i] = j;
            }
        }

        // cout << r << " " << res << endl;

        if (res >= k) {
            rg = r;
        } else {
            lf = r;
        }
    }

    cout << lf << endl;

}