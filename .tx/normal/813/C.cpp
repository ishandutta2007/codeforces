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

const int N = 222222;

vector<int> g[N];
int h[N];
bool used[N];

void calc_h(int v, int p, int ch) {
    h[v] = ch;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        calc_h(i, v, ch + 1);
    }
}

void dfs(int v, int d) {
    used[v] = true;
    for (int i : g[v]) {
        if (!used[i] && h[i] > d + 1) {
            dfs(i, d + 1);
        }
    }
}

void solve(istream& cin, ostream& cout) {
    int n, s;
    cin >> n >> s;
    --s;
    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    calc_h(0, -1, 0);
    dfs(s, 0);
    int ans = 0;
    rep(i, 0, n) {
        if (used[i]) {
            ans = max(ans, h[i]);
        }
    }

    cout << ans * 2;
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
}//erizqt