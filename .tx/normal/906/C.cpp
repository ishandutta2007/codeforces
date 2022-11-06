#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)
#define lbit(n) (n & (~(n - 1)))

#define STRESS 0
using lint = long long;

bool clq[1 << 22];
int d[1 << 22];
int pms[1 << 22];
int pa[1 << 22];


int ns[22];
int p2[shl(22)];

void solve(istream& cin, ostream& cout) {
    rep(i, 0, 22) {
        p2[shl(i)] = i;
    }
    int n, m;
    cin >> n >> m;
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        ns[x] |= shl(y);
        ns[y] |= shl(x);
    }

    fill(d, d + shl(22), 1e9);

    rep(ms, 1, shl(n)) {
        int l = lbit(ms);
        if (l == ms) {
            clq[ms] = true;
            d[ms] = 0;
            continue;
        }
        int nn = ms ^ l;
        int i = p2[l];
        if ((nn & ns[i]) == nn && clq[nn]) {
            clq[ms] = true;
            d[ms] = 0;
        }
    }

    fill(pms, pms + shl(22), -1);
    fill(pa, pa + shl(22), -1);

    rep(ms, 1, shl(n)) {
        int t = ms;
        while (t) {
            int l = lbit(t);
            int i = p2[l];
            int nms = ms | ns[i];
            if (d[nms] > d[ms] + 1) {
                d[nms] = d[ms] + 1;
                pms[nms] = ms;
                pa[nms] = i;
            }
            t ^= l;
        }
    }

    int ms = shl(n) - 1;
    cout << d[ms] << "\n";
    vector<int> ans;
    while (pa[ms] != -1) {
        ans.push_back(pa[ms]);
        ms = pms[ms];
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) {
        cout << i + 1 << " ";
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