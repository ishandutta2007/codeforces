#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 5011

int n, m, i, j, x, y;
int gr[maxN];
ll T, z;
vector< pair<int, ll> > list[maxN], from[maxN];

ll dp[maxN][maxN];
queue<int> Q;

vector<int> way;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%lld", &n, &m, &T);
    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        list[x].pb(mp(y, z));
        from[y].pb(mp(x, z));
        gr[y]++;
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            dp[i][j] = T + 1;

    dp[1][1] = 0;

    for (i = 1; i <= n; i++) {
        if (gr[i]) continue;
        Q.push(i);
    }

    while (!Q.empty()) {
        int node = Q.front(); Q.pop();

        for (auto to : list[node]) {
            for (i = 1; i < n; i++)
                dp[to.first][i + 1] = min(dp[to.first][i + 1], dp[node][i] + to.second);
            if (--gr[to.first] == 0)
                Q.push(to.first);
        }
    }

    int ans = 0;
    for (i = 1; i <= n; i++)
        if (dp[n][i] <= T)
            ans = i;

    printf("%d\n", ans);

    int node = n;
    int cnt = ans;

    way.pb(n);
    for (; cnt > 1; cnt--) {
        for (auto e : from[node]) {
            if (dp[e.first][cnt - 1] + e.second == dp[node][cnt]) {
                node = e.first;
                way.pb(node);
                break;
            }
        }
    }

    reverse(way.begin(), way.end());
    for (auto e : way)
        printf("%d ", e);

    return 0;
}