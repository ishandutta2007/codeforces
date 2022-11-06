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

#define maxN 100011

int n, m, i, x, y;
char ch;
vector< pair<int, int> > list[maxN];

bool good;
int cnt;
vector<int> act;
int state[maxN];
bool us[maxN];

int how;
vector<int> best;

void dfs(int node, int target) {
    us[node] = true;
    act.pb(node);

    // get needed state
    state[node] = 0;
    for (auto to : list[node]) {
        if (!us[to.first]) continue;

        state[node] = target ^ state[to.first] ^ to.second;
    }

    // check if it is possible
    for (auto to : list[node]) {
        if (!us[to.first]) continue;

        if ((target ^ state[to.first] ^ to.second) != state[node])
            good = false;
    }

    if (!good) return;


    // go down
    cnt += state[node];
    for (auto to : list[node])
        if (!us[to.first])
            dfs(to.first, target);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d %d %c\n", &x, &y, &ch);
        list[x].pb(mp(y, (ch == 'R' ? 0 : 1)));
        list[y].pb(mp(x, (ch == 'R' ? 0 : 1)));
    }

    how = n + 3;
    best = {};

    // try RED
    memset(us, 0, sizeof(us));
    good = true;

    for (i = 1; i <= n && good; i++) {
        if (us[i]) continue;

        act.clear(); cnt = 0;
        dfs(i, 0);

        if (cnt > act.size() - cnt)
            for (auto e : act)
                state[e] ^= 1;
    }

    cnt = 0;
    for (i = 1; i <= n; i++) cnt += state[i];

    if (cnt < how && good) {
        how = cnt;
        best.clear();
        for (i = 1; i <= n; i++)
            if (state[i])
                best.pb(i);
    }

    // try BLUE
    memset(us, 0, sizeof(us));
    good = true;

    for (i = 1; i <= n && good; i++) {
        if (us[i]) continue;

        act.clear(); cnt = 0;
        dfs(i, 1);

        if (cnt > act.size() - cnt)
            for (auto e : act)
                state[e] ^= 1;
    }

    cnt = 0;
    for (i = 1; i <= n; i++) cnt += state[i];

    if (cnt < how && good) {
        how = cnt;
        best.clear();
        for (i = 1; i <= n; i++)
            if (state[i])
                best.pb(i);
    }


    // conclude

    if (how > n) {
        printf("-1");
        return 0;
    }

    printf("%d\n", best.size());
    for (int e : best)
        printf("%d ", e);


    return 0;
}