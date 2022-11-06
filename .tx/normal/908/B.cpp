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

string a[55];
pair<int, int> dir[4];

int b[55][55];

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    int sx = -1, sy = -1;
    int ex = -1, ey = -1;
    rep(i, 0, n) {
        cin >> a[i];
        rep(j, 0, m) {
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (a[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    string s;
    cin >> s;
    dir[0] = {-1, 0};
    dir[1] = {1, 0};
    dir[2] = {0, 1};
    dir[3] = {0, -1};
    sort(dir, dir + 4);
    int ans = 0;
    do {
        int x = sx;
        int y = sy;
        for (char c : s) {
            auto t = dir[c - '0'];
            x += t.first;
            y += t.second;
            if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '#') {
                break;
            }
            if (a[x][y] == 'E') {
                ans++;
                break;
            }
        }
    } while (next_permutation(dir, dir + 4));
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