#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

vector<int> depth[5005];
int p[5005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, d;
        cin >> n >> d;
        if (d > n * (n - 1) / 2) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i <= n; i++) depth[i].clear();
        depth[0].pb(1);
        int cur = 1;
        for (int i = 2; i <= n; i++) {
            depth[cur].pb(i);
            if (sz(depth[cur]) == 2 * sz(depth[cur - 1])) cur++;
        }
        if (sz(depth[cur]) == 0) cur--;
        int curD = 0;
        for (int i = 1; i <= cur; i++) {
            curD += sz(depth[i]) * i;
        }
        if (curD > d) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        while (curD < d) {
            for (int i = cur; i >= 1; i--) {
                if (depth[i].size() != 1) {
                    int u = depth[i].back();
                    depth[i].pop_back();
                    depth[i + 1].pb(u);
                    break;
                }
            }
            if (depth[cur + 1].size()) cur++;
            curD++;
        }
        for (int i = cur; i >= 1; i--) {
            for (int j = 0; j < sz(depth[i]); j++) {
                p[depth[i][j]] = depth[i - 1][j / 2];
            }
        }
        for (int i = 2; i <= n; i++) {
            cout << p[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}