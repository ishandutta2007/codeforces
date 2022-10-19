#include <bits/stdc++.h>

using namespace std;

#ifdef GAREN
#include <cp-template/debugger.hpp>
#else
#define debug(...) 42
#endif

void run_case(int test) {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    bool comp = false;
    for (int i = 2; i * i <= sum; i++) {
        if (sum % i == 0) comp = true;
    }
    if (comp) {
        cout << n << '\n';
        for (int i = 0; i < n; i++) cout << i + 1 << ' ';
        cout << '\n';
    } else {
        int del = -1;
        cout << n - 1 << '\n';
        for (int i = 0; i < n; i++) {
            if (a[i] % 2) {
                del = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) if (i != del) cout << i + 1 << ' ';
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    cin >> tests;
    for (int test = 1; test <= tests; test++) run_case(test);
    return 0;
}