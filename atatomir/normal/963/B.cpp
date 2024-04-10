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

const int maxN = 200011;

int n, i, x, cnt;
vector<int> list[maxN];
int id[maxN], gr[maxN];
bool done[maxN];

priority_queue< pair<int, int> > H;

void dfs(int node, int root) {
    id[node] = ++cnt;
    for (auto to : list[node])
        if (to != root)
            dfs(to, node);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x != 0) {
            list[i].pb(x);
            list[x].pb(i);
        }
    }

    if (n % 2 == 0) {
        printf("NO");
        return 0;
    }

    printf("YES\n");
    dfs(1, 0);

    for (i = 1; i <= n; i++) {
        gr[i] = list[i].size();
        if (gr[i] % 2 == 0) H.push(mp(id[i], i));
    }

    while (!H.empty()) {
        int node = H.top().second;
        H.pop();

        if (done[node]) continue;
        if (gr[node] % 2 == 1) continue;
        done[node] = true;

        printf("%d ", node);
        for (auto to : list[node]) {
            if (done[to]) continue;
            if ( (--gr[to]) % 2 == 0)
                H.push(mp(id[to], to));
        }
    }


    return 0;
}