// #pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>
// #include <iomanip>
// #include <random>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
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
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;

    int tests = 1;
    // cin >> tests;

    while (tests--) {
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

vector<int> f(const vector<int> &arr) { 
    int x = arr[0];
    int cnt = 1;
    vector<int> res;
    for (int i = 1; i < sz(arr); ++i) {
        if (arr[i] == x) {
            ++cnt;
        } else {
            res.push_back(cnt);
            cnt = 1;
            x = arr[i];
        }
    }
    res.push_back(cnt);
    sort(all(res));
    return res;
}

vector<int> fk(vector<int> arr, int k) {
    for (int i = 0; i < k; ++i) {
        arr = f(arr);
    }
    return arr;
}

vector<int> g(const vector<int> &arr) {
    vector<int> res;
    int x = 1;
    for (int i = sz(arr) - 1; i >= 0; --i) {
        for (int j = 0; j < arr[i]; ++j) {
            res.push_back(x);
        }
        ++x;
    }
    return res;
}


int eval(const vector<int> &arr) {
    int x = 0;
    for (int i = 0; i < sz(arr); ++i) {
        x += (sz(arr) - i) * arr[i];
    }
    return x;
}

vector<int> arr;

int cnt = 0;

set<vector<int>> setik;

void brute_force(int n, int k, int m = 1) {
    arr.push_back(m);
    if (eval(g(arr)) <= n) {
        setik.insert(fk(arr, k - 3));

        ++cnt;
        brute_force(n, k, m);
        arr.pop_back();
        brute_force(n, k, m + 1);
    } else {
        arr.pop_back();
    }
}

const int MAXN = 2022;
int dp[MAXN][MAXN];

// set<vector<int>> setik_naive;
 
// void brute_force_naive(int n, int m = 1) {
//     if (m > n) {
//         return;
//     }
//     arr.push_back(m);
//     setik_naive.insert(fk(arr, 3));
//     brute_force_naive(n - m, m);
//     arr.pop_back();
//     brute_force_naive(n, m + 1);
// }

void solve() {  
    int n, k;
    cin >> n >> k;

    if (k >= 12) {
        cout << 1 << endl;
        return;
    }

    if (k == 1) {

        dp[0][0] = 1;
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = dp[i - 1][j - 1];
                add(dp[i][j], dp[i - j][j]);

                add(res, dp[i][j]);
            }
        }

        cout << res << endl;

    } else if (k == 2) {
        dp[0][0] = 1;
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * (j + 1) / 2 <= i; ++j) {
                dp[i][j] = dp[i - j][j - 1];
                add(dp[i][j], dp[i - j * (j + 1) / 2][j]);
                add(res, dp[i][j]);
            }
        }

        cout << res << endl;

    } else {
        brute_force(n, k);
        cout << sz(setik) << endl;
    }


    // int n;
    // cin >> n;
    // brute_force(n);

    // cerr << cnt << endl;
}