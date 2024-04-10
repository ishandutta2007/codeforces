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
    freopen("input.txt", "r", stdin);
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

const int P = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void mul(int &a, int b) {
    a = ll(a) * b % P;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; 
        --a[i];
    }

    vector<vector<int>> arr(n);
    for (int i = 0; i < m; ++i) {
        int f, h;
        cin >> f >> h;
        --f;
        arr[f].push_back(h);
    }

    for (int i = 0; i < n; ++i) {
        sort(all(arr[i]));
    }

    vector<int> ptr1(n), ptr2(n);
    vector<int> cnt1(n), cnt2(n);

    for (int i = 0; i < n; ++i) {
        int t = a[i];
        ++cnt2[t];
        while (ptr2[t] < sz(arr[t]) && arr[t][ptr2[t]] == cnt2[t]) {
            ++ptr2[t];
        }
    }

    int cnt = 0;
    int val = 1;

    for (int i = 0; i < n; ++i) {
        if (ptr2[i] > 0) {
            ++cnt;
            mul(val, ptr2[i]);
        }
    }

    for (int i = 0; i < n; ++i) {   
        int t = a[i];
        while (ptr2[t] > 0 && arr[t][ptr2[t] - 1] == cnt2[t]) {
            --ptr2[t];
        }
        --cnt2[t];

        int prv = ptr1[t];

        ++cnt1[t];
        while (ptr1[t] < sz(arr[t]) && arr[t][ptr1[t]] == cnt1[t]) {
            ++ptr1[t];
        }

        if (prv == ptr1[t]) {
            continue;
        }

        int cur_cnt = 1;
        int cur_val = ptr1[t] - prv;
        
        if (ptr2[t] - (ptr2[t] >= ptr1[t]) > 0) {
            ++cur_cnt;
            mul(cur_val, ptr2[t] - (ptr2[t] >= ptr1[t]));
        }

        for (int j = 0; j < n; ++j) {
            if (j == t) {
                continue;
            }
            if (ptr1[j] == 1 && ptr2[j] == 1) {
                cur_cnt += 1;
                mul(cur_val, 2);
            } else if (ptr1[j] > 0 && ptr2[j] > 0) {
                cur_cnt += 2;
                mul(cur_val, min(ptr1[j], ptr2[j]));
                mul(cur_val, max(ptr1[j], ptr2[j]) - 1);
            } else if (ptr1[j] > 0) {
                cur_cnt += 1;
                mul(cur_val, ptr1[j]);
            } else if (ptr2[j] > 0) {
                cur_cnt += 1;
                mul(cur_val, ptr2[j]);
            }
        }

        // cerr << cur_cnt << " " << cur_val << endl;

        if (cur_cnt > cnt) {
            cnt = cur_cnt;
            val = 0;
        }
        if (cur_cnt == cnt) {
            add(val, cur_val);
        }
    }

    cout << cnt << " " << val << endl;
}