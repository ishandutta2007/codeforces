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

const int maxN = 2018;
const int cap = 4;
const int maxLvl = 10;
const int inf = 1 << 30;
const int maxConfs = 811;

int n, i, j, k, conf, cnt;
int from[maxN], to[maxN];
int id[maxLvl][maxLvl][maxLvl][maxLvl];
int add[maxConfs][10], rm[maxConfs][10];

vector< vector<int> > states;
int dp[maxN][maxConfs][10];
vector<int> lvl_range = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1};

void add_state(int a, int b, int c, int d) {
    id[a][b][c][d] = ++cnt;
    states.pb({a, b, c, d});
}

int get_rm(vector<int> conf, int v) {
    int i, j;

    i = -1;
    for (j = 0; j < conf.size(); j++)
        if (conf[j] != v)
            conf[++i] = conf[j];

    for (i++; i < 4; i++) conf[i] = 0;
    return id[conf[0]][conf[1]][conf[2]][conf[3]];
}

int get_add(vector<int> conf, int v) {
    int i, j;

    if (conf[3] != 0) return 0;
    for (i = 0; conf[i] != 0 && conf[i] < v; i++);
    for (j = 3; j > i; j--) conf[j] = conf[j - 1];
    conf[i] = v;
    return id[conf[0]][conf[1]][conf[2]][conf[3]];
}

void pre() {
    int i, j, k, l;

    add_state(0, 0, 0, 0);

    for (i = 1; i <= 9; i++)
        add_state(i, 0, 0, 0);

    for (i = 1; i <= 9; i++)
        for (j = i; j <= 9; j++)
            add_state(i, j, 0, 0);

    for (i = 1; i <= 9; i++)
        for (j = i; j <= 9; j++)
            for (k = j; k <= 9; k++)
                add_state(i, j, k, 0);

    for (i = 1; i <= 9; i++)
        for (j = i; j <= 9; j++)
            for (k = j; k <= 9; k++)
                for (l = k; l <= 9; l++)
                    add_state(i, j, k, l);

    cerr << cnt << '\n';

    for (i = 0; i < states.size(); i++) {
        for (j = 1; j <= 9; j++) {
            rm[i + 1][j] = get_rm(states[i], j);
            add[i + 1][j] = get_add(states[i], j);
        }
    }
}

void upd(int& a, int b) {
    if (a > b) a = b;
}

void solve() {
    int i, j, k, conf, lvl;

    for (i = 0; i <= n; i++)
        for (j = 0; j <= cnt; j++)
            for (k = 0; k < 10; k++)
                dp[i][j][k] = inf;

    dp[0][1][1] = 0;
    for (i = 0; i <= n; i++) {
        for (conf = cnt; conf >= 1; conf--) {
            for (auto lvl : lvl_range) {
                auto& act = dp[i][conf][lvl];
                if (act >= inf) continue;

                //! go up one level
                if (lvl + 1 <= 9) {
                    upd(dp[i][ rm[conf][lvl + 1] ][lvl + 1], act + 1);
                }

                //! go down one level
                if (lvl - 1 >= 1) {
                    upd(dp[i][ rm[conf][lvl - 1] ][lvl - 1], act + 1);
                }

                //! get next person
                if (from[i + 1] == lvl) {
                    upd(dp[i + 1][ add[conf][to[i + 1]] ][lvl], act + 2);
                }
            }
        }
    }

    int ans = dp[n][1][1];
    for (i = 2; i <= 9; i++) upd(ans, dp[n][1][i]);

    printf("%d\n", ans);
}

int main()
{
   // freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d%d", &from[i], &to[i]);
    pre();
    solve();


    return 0;
}