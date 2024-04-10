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

vector<int> rg[111111];
int d[111111];

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        rg[y].push_back(x);
        d[x]++;
    }
    priority_queue<int> q;
    rep(i, 0, n) {
        if (d[i] == 0) {
            q.push(i);
        }
    }
    vector<int> ans(n);
    repr(i, n, 0) {
        int v = q.top();
        q.pop();
        ans[v] = i;
        for (int i : rg[v]) {
            d[i]--;
            if (d[i] == 0) {
                q.push(i);
            }
        }
    }

    rep(i, 0, n) {
        cout << ans[i] + 1 << " ";
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
}//qnzwra