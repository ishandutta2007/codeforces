#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 3005;
char c[MAXN][MAXN];
int l[MAXN][MAXN], r[MAXN][MAXN], d[MAXN][MAXN], fen[2 * MAXN][MAXN];
vector< pair<int, int> > ev[MAXN];

void add(int t, int x, int val) {
    for(; x < MAXN; x |= x + 1)
        fen[t][x] += val;
}

int getPref(int t, int x) {
    int res = 0;
    for(; x >= 0; x = (x & (x + 1)) - 1)
        res += fen[t][x];
    return res;
}

int get(int t, int l, int r) {
    return getPref(t, r) - (l? getPref(t, l - 1) : 0);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", c[i]);
    for(int i = 0; i < n; i++) {
        l[i][0] = 0;
        for(int j = 1; j < m; j++)
            l[i][j] = (c[i][j - 1] == 'z'? l[i][j - 1] : j);
    }
    for(int i = 0; i < n; i++) {
        r[i][m - 1] = m - 1;
        for(int j = m - 2; j >= 0; j--)
            r[i][j] = (c[i][j + 1] == 'z'? r[i][j + 1] : j);
    }
    for(int j = 0; j < m; j++)
        d[0][j] = j;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m - 1; j++)
            d[i][j] = (c[i - 1][j + 1] == 'z'? d[i - 1][j + 1] : j);
        d[i][m - 1] = m - 1;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ev[l[i][j]].push_back(make_pair(i, j));
    long long ans = 0;
    for(int j = 0; j < m; j++) {
        for(size_t i = 0; i < ev[j].size(); i++) {
            int x = ev[j][i].first, y = ev[j][i].second;
            add(x + y, y, 1);
        }
        for(int i = 0; i < n; i++)
            if(c[i][j] == 'z')
                ans += get(i + j, j, min(r[i][j], d[i][j]));
    }
    cout << ans << '\n';
    return 0;
}