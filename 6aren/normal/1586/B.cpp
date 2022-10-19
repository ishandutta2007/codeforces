#include <bits/stdc++.h>

using namespace std;

#ifdef GAREN
#include <cp-template/debugger.hpp>
#else
#define debug(...) 42
#endif

void run_case(int test) {
    int n, m;
    cin >> n >> m;
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        s.erase(b);
    }
    int root = *s.begin();
    for (int i = 1; i <= n; i++) {
        if (i != root) cout << root << ' ' << i << '\n';
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