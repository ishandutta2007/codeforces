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

#define maxN 100011

int n, i;
int deg[maxN], sum[maxN];
queue<int> Q;
vector< pair<int, int> > edges;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &deg[i], &sum[i]);
        if (deg[i] == 1)
            Q.push(i);
    }

    while (!Q.empty()) {
        int node = Q.front(); Q.pop();
        if (deg[node] != 1) continue;

        edges.pb(mp(node, sum[node]));
        sum[ sum[node] ] ^= node;
        if (--deg[sum[node]] == 1)
            Q.push(sum[node]);
    }

    printf("%d\n", edges.size());
    for (auto e : edges)
        printf("%d %d\n", e.first, e.second);


    return 0;
}