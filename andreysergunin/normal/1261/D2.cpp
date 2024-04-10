#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

const int P = 998244353;

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void sub(int &a, int b) {
    a -= b;
    if (a < P) {
        a += P;
    }
}

void mul(int &a, int b) {
    a = ll(a) * b % P;
}

int binPow(int a, int b) {
    int res = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) {
            mul(res, a);
        }
        mul(a, a);
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    } 

    vector<int> arr = {a[0]};
    for (int i = 1; i < n; ++i) {   
        if (arr.back() != a[i]) {
            arr.push_back(a[i]);
        }
    }

    while (sz(arr) > 0 && arr[0] == arr.back()) {
        arr.pop_back();
    }
    if (sz(arr) == 1) {
        cout << 0 << endl;
        return;
    }

    int coef = 1;
    for (int i = sz(arr); i < n; ++i) {
        mul(coef, k);
    }

    n = sz(arr);

    vector<int> fact(n + 1);
    vector<int> r(n + 1);
    vector<int> rfact(n + 1);

    r[1] = 1;
    for (int i = 2; i <= n; ++i) {
        r[i] = r[P % i];
        mul(r[i], P / i);
        r[i] = P - r[i];
    }

    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = rfact[i - 1];
        mul(rfact[i], r[i]);
    }

    int x = 0;

    for (int i = 0; 2 * i <= n; ++i) {
        int cur = fact[n];
        mul(cur, rfact[i]);
        mul(cur, rfact[i]);
        mul(cur, rfact[n - 2 * i]);
        mul(cur, binPow(k - 2, n - 2 * i));
        add(x, cur);
    }

    int res = binPow(k, n);
    sub(res, x);
    mul(res, (P + 1) / 2);
    mul(res, coef);

    cout << res << endl;
}

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

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}