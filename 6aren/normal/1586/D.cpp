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
    auto query = [&](vector<int> a) {
        cout << "? ";
        for (int e : a) cout << e << ' ';
        cout << endl;
        int res;
        cin >> res;
        return res - 1;
    };

    vector<int> res(n);
    // find res.back
    for (int i = n; i >= 1; i--) {
        vector<int> a(n);
        a[n - 1] = i;
        for (int j = 0; j + 1 < n; j++) a[j] = 1;
        int foo = query(a);
        if (foo == -1) continue;
        res.back() = n + 1 - i;
        break;
    }
    if (res.back() == 0) res.back() = n;
    for (int i = 1; i <= n; i++) {
        if (i == res.back()) continue;
        int to_n = n + 1 - i;
        vector<int> a(n, to_n);
        a.back() = n + 1 - res.back();
        int id = query(a);
        assert(id != -1);
        res[id] = i;
    }
    cout << "! ";
    for (int e : res) cout << e << ' ';
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    for (int test = 1; test <= tests; test++) run_case(test);
    return 0;
}