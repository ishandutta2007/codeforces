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

int n, i, x;
vector<int> list[maxN];
int cnt[maxN];

void dfs(int node, int lvl) {
    cnt[lvl]++;

    for (auto to : list[node])
        dfs(to, lvl + 1);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 2; i <= n; i++) {
        scanf("%d", &x);
        list[x].pb(i);
    }

    dfs(1, 0);

    int ans = 0;
    for (i = 0; i <= n; i++)
        ans += cnt[i] % 2;

    printf("%d", ans);



    return 0;
}