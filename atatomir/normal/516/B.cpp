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

#define maxN 3011

const int defX[4] = {-1, 1, 0, 0};
const int defY[4] = {0, 0, -1, 1};

int n, m, i, j;
char s[maxN][maxN];
vector< pair<int, int> > S[6];

int get(int x, int y) {
    int i, ans = 0;

    for (i = 0; i < 4; i++) {
        int xx = x + defX[i];
        int yy = y + defY[i];
        if (s[xx][yy] == '.') ans++;
    }
    return ans;
}

void no_sol() {
    printf("Not unique");
    exit(0);
}

void around(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + defX[i];
        int yy = y + defY[i];
        if (s[xx][yy] != '.') continue;
        S[get(xx, yy)].pb(mp(xx, yy));
    }
}

void combine(int x, int y) {
    if (s[x + 1][y] == '.') {
        s[x][y] = '^';
        s[x + 1][y] = 'v';
        around(x, y);
        around(x + 1, y);
        return;
    }

    if (s[x - 1][y] == '.') {
        s[x][y] = 'v';
        s[x - 1][y] = '^';
        around(x, y);
        around(x - 1, y);
        return;
    }

    if (s[x][y + 1] == '.') {
        s[x][y] = '<';
        s[x][y + 1] = '>';
        around(x, y);
        around(x, y + 1);
        return;
    }

    if (s[x][y - 1] == '.') {
        s[x][y] = '>';
        s[x][y - 1] = '<';
        around(x, y);
        around(x, y - 1);
        return;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n", &n, &m);
    for (i = 1; i <= n; i++) scanf("%s\n", s[i] + 1);

    for (i = 1; i <= n; i++) s[i][0] = s[i][m + 1] = '*';
    for (i = 1; i <= m; i++) s[0][i] = s[n + 1][i] = '*';

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (s[i][j] != '.') continue;
            S[get(i, j)].pb(mp(i, j));
        }
    }

    while (S[0].size() || S[1].size()) {
        if (S[0].size()) {
            auto act = S[0].back(); S[0].pop_back();
            if (s[act.first][act.second] != '.') continue;
            no_sol();
        }

        if (S[1].size()) {
            auto act = S[1].back(); S[1].pop_back();
            if (s[act.first][act.second] != '.') continue;
            if (get(act.first, act.second) != 1) continue;
            combine(act.first, act.second);
            continue;
        }

        no_sol();
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (s[i][j] == '.')
                no_sol();

    for (i = 1; i <= n; i++)
        s[i][m + 1] = '\0', printf("%s\n", s[i] + 1);


    return 0;
}