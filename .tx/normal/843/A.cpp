#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

int a[111111];
int b[111111];

vector<vector<int>> ans;
bool used[111111];

void dfs(int v) {
    used[v] = true;
    ans.back().push_back(v);
    if (!used[a[v]]) {
        dfs(a[v]);
    }
}

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    rep(i, 0, n) {
        a[i] = lower_bound(b, b + n, a[i]) - b;
    }

    rep(i, 0, n) {
        if (!used[i]) {
            ans.push_back(vector<int>());
            dfs(i);
        }
    }

    cout << ans.size() << "\n";
    for (auto& i : ans) {
        cout << i.size() << " ";
        for (int j : i) {
            cout << j + 1 << " ";
        }
        cout << "\n";
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}