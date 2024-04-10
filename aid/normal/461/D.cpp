#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 100 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
vector< pair<int, char> > g[2][MAXN / 2];
char c[2][MAXN / 2];

bool dfs(int gr, int v) {
    for(size_t i = 0; i < g[gr][v].size(); i++) {
        int u = g[gr][v][i].first;
        char col = c[gr][v] ^ g[gr][v][i].second;
        if(c[gr][u] == -1) {
            c[gr][u] = col;
            if(!dfs(gr, u))
                return false;
        }
        else if(c[gr][u] != col)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        x--;
        y--;
        int l = abs(x - y), r = x + y;
        if(r >= n)
            r -= 2 * (r - n + 1);
        int gr = l & 1;
        l >>= 1;
        r = (r >> 1) + 1;
        g[gr][l].push_back(make_pair(r, c == 'o'));
        g[gr][r].push_back(make_pair(l, c == 'o'));
    }
    int ans = 1;
    for(int i = 0; i < 2; i++)
        for(int j = 0; 2 * j + i - 1 <= n; j++)
            c[i][j] = -1;
    for(int i = 0; i < 2; i++)
        for(int j = 0; 2 * j + i - 2 <= n; j++)
            if(c[i][j] == -1) {
                c[i][j] = 0;
                if(!dfs(i, j)) {
                    cout << 0 << '\n';
                    return 0;
                }
                if(j != 0)
                    ans = (2 * ans) % MOD;
            }
    cout << ans << '\n';
    return 0;
}