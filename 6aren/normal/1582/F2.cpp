#include <bits/stdc++.h>
using namespace std;

#ifdef GAREN
#include <cp/debugger.hpp>
#else
#define debug(...) 42
#endif

const int MAX = (1 << 13);

int r[MAX];
vector<int> g[MAX];
int ans[MAX];

void run_case(int test) {
    for (int i = 0; i < MAX; i++) {
        r[i] = MAX - 1;
    }
    r[0] = -1;
    ans[0] = true;
    for (int i = 0; i < MAX; i++) {
        g[i].push_back(0);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int sum_xor : g[x]) {
            int to = (sum_xor ^ x);
            ans[to] = true;
            while (r[to] > x) {
                g[r[to]].push_back(to);
                r[to]--;
            }
        }
        g[x].clear();
    }
    vector<int> res;
    for (int i = 0; i < MAX; i++) {
        if (ans[i]) {
            res.push_back(i);
        }
    }
    cout << res.size() << '\n';
    for (int e : res) {
        cout << e << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); 
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests;
    tests = 1;
    for (int test = 1; test <= tests; test++) {
        run_case(test);
    }
    return 0;
}