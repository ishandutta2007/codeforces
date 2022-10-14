#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
const int mod = 1e9 + 7, x = 864197532, N = 5087, logN = 13;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, m, t, _id = 0;
    cin >> q >> m; q++;
    map <string, int> m1;
    string s;
    set <int> now;
    vector <vector <bool>> edge(m, vector <bool>(m, false));
    while (q--) {
        cin >> t;
        if (!q || t == 1) {
            for (int i : now) {
                for (int j : now) if (i ^ j) {
                    edge[i][j] = edge[j][i] = true;
                }
            }
            now.clear();
        } else {
            cin >> s;
            if (!m1.count(s)) {
                m1[s] = _id++;
            }
            now.insert(m1[s]);
        }
    }
    q = 50000;
    vector <int> p(m);
    iota(all(p), 0);
    int ans = 0;
    while (q--) {
        random_shuffle(all(p));
        vector <bool> vis(m, false);
        int tmp = 0;
        for (int i : p) if (!vis[i]) {
            vis[i] = true;
            fop (j,0,m) if (edge[i][j]) {
                vis[j] = true;
            }
            tmp++;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}