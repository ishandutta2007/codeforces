#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int MAXN = (int) 300 + 7;
const int MAX = MAXN * MAXN + MAXN;

int main() {
    int n, m;
    int k;
    scanf("%d%d%d", &n, &m, &k);
    vector <pair <int, int> > path;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                path.pb({i, j});
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                path.pb({i, j});
            }
        }
    }
    vector <vector <pair <int, int> > > tube;
    vector <pair <int, int> > cur;
    for (int i = 0; i < (int) path.size(); i++) {
        cur.pb(path[i]);
        if (cur.size() == 2 && k > 1) {
            tube.pb(cur);
            cur.clear(); 
            k--;
        }
    }
    tube.pb(cur);
    for (auto u : tube) {
        printf("%d ", (int) u.size());
        for (auto c : u) {
            printf("%d %d ", c.fc + 1, c.sc + 1);
        }
        puts("");
    }
}