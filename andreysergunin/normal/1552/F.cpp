#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
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

const int P = 998244353;

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void mul(int &a, int b) {
    a = ll(a) * b % P;
}

struct Portal {
    int x, y, s;
};

class BIT {
public:
    BIT(int n) {
        arr.resize(n);
    }
    
    void add(int pos, int val) {
        for (int i = pos; i < sz(arr); i |= i + 1) {
            ::add(arr[i], val);
        }
    }

    int sum(int pos) {
        int res = 0;
        for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
            ::add(res, arr[i]);
        }
        return res;
    }

private:
    vector<int> arr;
};


void solve() { 
    int n;
    cin >> n;
    vector<Portal> p(n);
    for (auto &[x, y, s] : p) {
        cin >> x >> y >> s;
    }
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        x[i] = p[i].x;
    }

    BIT bit(n + 1);

    int res = 0;
    for (int i = 0; i < n; ++i) {
        auto [xx, yy, ss] = p[i];

        int j = lower_bound(all(x), yy) - x.begin();

        int to_add = x[j] - yy;
        if (j != i) {
            add(to_add, x[i] - x[i - 1]);
            add(to_add, bit.sum(n - j - 1));
        }
        if (ss) {
            add(res, to_add);
        }
        if (i) {
            bit.add(n - i, x[i] - x[i - 1]);
        }
        bit.add(n - i - 1, to_add);
    }
    add(res, x[n - 1]);
    add(res, 1);
    cout << res << endl;
}