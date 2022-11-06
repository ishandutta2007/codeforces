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

#define maxN 2017

int n, i, j, x;
int edg[maxN][maxN], mini = 1000000000;
ll dist[maxN];
bool done[maxN];


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        dist[i] = 1LL << 60;
        for (j = i + 1; j <= n; j++)
            scanf("%d", &edg[i][j]), mini = min(mini, edg[i][j]);
    }

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            edg[j][i] = edg[i][j] = edg[i][j] - mini;

            dist[i] = min(dist[i], 2LL * edg[i][j]);
            dist[j] = min(dist[j], 2LL * edg[i][j]);
        }
    }

    for (int tms = 1; tms <= n; tms++) {
        pair<ll, int> best = mp(1LL << 60, -1);
        for (i = 1; i <= n; i++)
            if (!done[i])
                best = min(best, mp(dist[i], i));

        int node = best.second;
        done[node] = true;
        for (i = 1; i <= n; i++)
            if (!done[i])
                dist[i] = min(dist[i], dist[node] + edg[node][i]);
    }

    for (i = 1; i <= n; i++)
        cout << dist[i] + 1LL * (n - 1) * mini << '\n';





    return 0;
}