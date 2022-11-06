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
template <typename T> using vc = std::vector<T>;

string s;
vector<int> g[333333];
int used[333333];

bool has_cycle(int v) {
    if (used[v] == 1) {
        return true;
    }
    if (used[v] == 2) {
        return false;
    }
    used[v] = 1;
    for (int i : g[v]) {
        if (has_cycle(i)) {
            return true;
        }
    }
    used[v] = 2;
    return false;
}

vector<int> ts;
void build_ts(int v) {
    if (used[v]) {
        return;
    }
    used[v] = 1;
    for (int i : g[v]) {
        build_ts(i);
    }
    ts.push_back(v);
}

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    cin >> s;
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
    }

    rep(i, 0, n) {
        if (has_cycle(i)) {
            cout << -1;
            return;
        }
    }

    fill(used, used + n, 0);
    rep(i, 0, n) {
        build_ts(i);
    } 

    int ans = 0;
    rep(c, 'a', 'a' + 26) {
        vector<int> d(n);
        for (int i : ts) {
            for (int v : g[i]) {
                d[i] = max(d[i], d[v]);
            }
            if (s[i] == c) {
                d[i]++;
            }
        }
        ans = max(ans, *max_element(d.begin(), d.end()));
    }
    cout << ans;
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