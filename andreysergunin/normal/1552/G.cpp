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

void solve() { 
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(m);
    vector<ll> a(m);
    for (int k = 0; k < m; ++k) {
        int s;
        cin >> s;
        arr[k].resize(s);
        for (int &i : arr[k]) {
            cin >> i;
            --i;
            a[k] ^= (1ll << i);
        }
    }

    vector<vector<ll>> sorts(m);
    for (int k = 0; k < m; ++k) {
        sorts[k].resize(sz(arr[k]) + 1);
        for (int i = 1; i <= sz(arr[k]); ++i) {
            sorts[k][i] = sorts[k][i - 1] | (1ll << arr[k][sz(arr[k]) - i]);
        }
    }

    vector<int> used(n);
    vector<vector<int>> blocks(m);
    for (int k = 0; k < m; ++k) {
        for (int i : arr[k]) {
            if (!used[i]) {
                blocks[k].push_back(i);
                used[i] = true;
            }
        }
    }

    if (n == 1) {
        cout << "ACCEPTED" << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cout << "REJECTED" << endl;
            return;
        }
    }

    auto check = [&](ll c) {
        if (!c) {
            return true;
        }
        for (int k = 0; k < m; ++k) {
            // cout << bitset<4>(a[k]) << endl;
            int cnt = __builtin_popcountll(c & a[k]);
            c &= ~a[k];
            c ^= sorts[k][cnt];
            // cout << bitset<4>(c) << endl;
        }
        int shift = __builtin_ctzll(c);
        c >>= shift;
        c += 1;
        c <<= shift;
        // cout << endl;

        return c == (1ll << n);
    };

    function<bool(int, ll)> gen = [&](int k, ll c) {
        if (k == m) {
            return check(c);
        }
        if (!gen(k + 1, c)) {
            return false;
        }
        for (int i : blocks[k]) {
            c ^= (1ll << i);
            if (!gen(k + 1, c)) {
                return false;
            }
        }
        return true;
    };

    cout << (gen(0, 0) ? "ACCEPTED" : "REJECTED") << endl;
}