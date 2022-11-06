#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 53
#define maxNodes (maxN * maxN + 11)

int defX[4] = {-1, 1, 0, 0};
int defY[4] = {0, 0, -1, 1};

int n, m, i, j, k;
char mat[maxN][maxN];

bool good;
vector< vector< pair<int, int> > > comps;
vector< pair<int, int> > aux;
bool us[maxN][maxN];

int ans;


void dfs(int x, int y) {
    us[x][y] = true;
    aux.pb(mp(x, y));

    for (int i = 0; i < 4; i++) {
        int xx = x + defX[i];
        int yy = y + defY[i];

        if (mat[xx][yy] == '@') good = false;
        if (mat[xx][yy] != '.') continue;

        if (!us[xx][yy]) dfs(xx, yy);
    }
}

bool cmp(const vector< pair<int, int> >& a, const vector< pair<int, int> >& b) {
    return a.size() < b.size();
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d\n", &n, &m, &k);
    for (i = 1; i <= n; i++) scanf("%s\n", mat[i] + 1);

    for (i = 1; i <= n; i++) mat[i][0] = mat[i][m + 1] = '@';
    for (i = 1; i <= m; i++) mat[0][i] = mat[n + 1][i] = '@';

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (mat[i][j] != '.') continue;
            if (us[i][j]) continue;

            good = true; aux.clear();
            dfs(i, j);

            if (good)
                comps.pb(aux);
        }
    }

    sort(comps.begin(), comps.end(), cmp);
    for (i = 0; i < comps.size() - k; i++)
        for (auto e : comps[i])
            mat[e.first][e.second] = '*', ans++;

    printf("%d\n", ans);
    for (i = 1; i <= n; i++, printf("\n"))
        for (j = 1; j <= m; j++)
            printf("%c", mat[i][j]);

    return 0;
}