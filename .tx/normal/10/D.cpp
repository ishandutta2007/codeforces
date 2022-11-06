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

int a[555];
int b[555];

int d[555][555];

map<int, vector<int>> inb;

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    rep(i, 0, m) {
        cin >> b[i];
        inb[b[i]].push_back(i);
    }

    memset(d, -1, sizeof(int) * 555 * 555);

    int mx = 0;

    rep(i, 0, n) {
        auto it = inb.find(a[i]);
        if (it == inb.end()) {
            continue;
        }
        auto& v = it->second;
        d[i][1] = v[0];
        mx = max(mx, 1);
        rep(j, 0, i) {
            if (a[j] >= a[i]) {
                continue;
            }
            rep(k, 1, n) {
                if (d[j][k] == -1) {
                    break;
                }
                auto t = upper_bound(v.begin(), v.end(), d[j][k]);
                if (t == v.end()) {
                    continue;
                }
                d[i][k + 1] = *t;
                mx = max(mx, k + 1);
            }
        }
    }

    cout << mx << "\n";
    vector<int> ans;
    int lp = 1e9;
    repr(i, n, 0) {
        if (d[i][mx] != -1 && (ans.empty() || a[i] < ans.back()) && d[i][mx] < lp) {
            ans.push_back(a[i]);
            lp = d[i][mx];
            --mx;
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i : ans) {
        cout << i << " ";
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
}//wlcdvm