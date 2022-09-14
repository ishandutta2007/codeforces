#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
// using ld = long double; 
using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

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

void mergeSort(int l, int r, string &s) {
    if (r - l == 1) {
        return;
    }

    int m = (l + r) / 2;
    mergeSort(l, m, s);
    mergeSort(m, r, s);

    int i = l, j = m;
    while (i < m && j < r) {
        if (i + 1 < m) {
            ++i;
            s += '0';
        } else {
            ++j;
            s += '1';
        }
    }
}

void solve() {  
    string s;
    // mergeSort(0, 1e5, s);
    // cout << s << endl;
    cin >> s;

    function<void(int, vector<pii>&)> gen = [&](int n, vector<pii> &arr) {
        if (n > 1) {
            gen(n / 2, arr);
            gen((n + 1) / 2, arr);
            arr.push_back({n / 2, (n + 1) / 2});
        }
    };

    int lf = 0, rg = 1e5 + 1;
    while (rg - lf > 1) {
        int n = (lf + rg) / 2;
        vector<pii> arr;
        gen(n, arr);
        
        int j = 0;
        bool ok = true;

        for (int i = 0; i < sz(arr); ++i) {
            auto [zeros, ones] = arr[i];

            for (; j < sz(s) && zeros && ones; ++j) {
                --(s[j] == '0' ? zeros : ones);
            }

            ok &= !zeros || !ones;
        }

        // cout << n << " " << j << " " << ok << endl;

        if (ok) {
            lf = n;
        } else {
            rg = n;
        }
    }

    int n = lf;
    // cout << n << endl;

    vector<pii> arr;
    gen(n, arr);
    
    int j = 0;
    vector<int> parts;
    for (int i = 0; i < sz(arr); ++i) {
        auto [zeros, ones] = arr[i];

        int init = j;
        for (; j < sz(s) && zeros && ones; ++j) {
            --(s[j] == '0' ? zeros : ones);
        }
        parts.push_back(j - init);
    }

    int k = sz(s);
    function<vector<int>(vector<int>)> construct = [&](vector<int> a) {
        int n = sz(a);
        if (n == 1) {
            return a;
        }
        vector<int> lf, rg;
        int zeros = n / 2, ones = (n + 1) / 2;
        int part = parts.back();

        int j = 0;
        for (int i = 0; i < parts.back(); ++i) {
            if (s[k - part + i] == '0') {
                lf.push_back(a[j++]);
                --zeros;
            } else {
                rg.push_back(a[j++]);
                --ones;
            }
        }
        assert(!zeros || !ones);

        while (zeros) {
            lf.push_back(a[j++]);
            --zeros;
        }

        while (ones) {
            rg.push_back(a[j++]);
            --ones;
        }

        k -= part;
        parts.pop_back();

        vector<int> res = construct(rg);
        for (int x : construct(lf)) {
            res.push_back(x);
        }
        rotate(res.begin(), res.begin() + sz(rg), res.end());
        return res;
    };

    vector<int> a(n);
    iota(all(a), 0);

    cout << n << endl;
    for (int x : construct(a)) {
        cout << x + 1 << " ";
    }
    cout << endl;
}