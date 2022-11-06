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

const int maxN = 100011;

int n, m, h, i, j;
int u[maxN], x[maxN], y[maxN];
vector<int> to[maxN], from[maxN];

bool us[maxN];
vector<int> S;
int color[maxN], cnt, pieces[maxN];
bool deny[maxN];

pair<int, int> ans = mp(maxN, -1);

void dfs_to(int node) {
    us[node] = true;
    for (auto e : to[node])
        if (!us[e])
            dfs_to(e);
    S.pb(node);
}

void dfs_from(int node) {
    color[node] = cnt;
    pieces[cnt]++;
    us[node] = true;

    for (auto e : from[node])
        if (!us[e])
            dfs_from(e);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> m >> h;
    for (i = 1; i <= n; i++) cin >> u[i];
    for (i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];

        if ((u[x[i]] + 1) % h == u[y[i]]) {
            to[x[i]].pb(y[i]);
            from[y[i]].pb(x[i]);
        }

        swap(x[i], y[i]);
        if ((u[x[i]] + 1) % h == u[y[i]]) {
            to[x[i]].pb(y[i]);
            from[y[i]].pb(x[i]);
        }
    }

    for (i = 1; i <= n; i++)
        if (!us[i])
            dfs_to(i);

    reverse(S.begin(), S.end());
    memset(us, 0, sizeof(us));

    for (auto node : S) {
        if (us[node]) continue;
        cnt++;
        dfs_from(node);
    }

    for (i = 1; i <= n; i++) {
        for (auto e : to[i]) {
            if (color[i] == color[e]) continue;
            deny[color[i]] = true;
        }
    }

    for (i = 1; i <= cnt; i++) {
        if (deny[i]) continue;
        ans = min(ans, mp(pieces[i], i));
    }

    printf("%d\n", ans.first);
    for (i = 1; i <= n; i++)
        if (color[i] == ans.second)
            printf("%d ", i);




    return 0;
}