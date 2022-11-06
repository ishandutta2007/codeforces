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

#define maxN 400011

int n, i, x, y, need;
vector<int> list[maxN];
int cnt[maxN];
bool us[maxN];

int up[maxN], down[maxN];
int can_be[maxN];

int n1[maxN], n2[maxN];

void dfs(int node) {
    us[node] = true;
    cnt[node] = 1;
    up[node] = down[node] = 0;

    for (int i = 0; i < list[node].size(); i++) {
        int to = list[node][i];

        if (us[to]) {
            list[node][i] = list[node].back();
            list[node].pop_back();
            i--;
            continue;
        }

        dfs(to);
        cnt[node] += cnt[to];
        down[node] = max(down[node], down[to]);
    }

    if (cnt[node] <= need)
        down[node] = cnt[node];
}

void solve(int node) {
    int bad = 0;
    int prob = 0;
    int i;

    if (n - cnt[node] > need) bad++;
    for (int to : list[node])
        if (cnt[to] > need)
            bad++, prob = to;

    if (bad == 0) can_be[node] = true;
    if (bad == 1) {
        if (n - cnt[node] > need) {
            // error up
            can_be[node] = (n - cnt[node] - up[node] <= need ? 1 : 0);
        } else {
            // error down
            can_be[node] = (cnt[prob] - down[prob] <= need ? 1 : 0);
        }
    }

    for (i = 0; i < list[node].size(); i++)
        n1[i] = n2[i] = down[list[node][i]];
    for (i = 1; i < list[node].size(); i++)
        n1[i] = max(n1[i], n1[i - 1]);
    for (i = list[node].size() - 2; i >= 0; i--)
        n2[i] = max(n2[i], n2[i + 1]);

    for (i = 0; i < list[node].size(); i++) {
        int to = list[node][i];

        up[to] = (n - cnt[to] <= need ? n - cnt[to] : 0);
        up[to] = max(up[node], up[to]);

        if (i > 0) up[to] = max(up[to], n1[i - 1]);
        if (i + 1 < list[node].size()) up[to] = max(up[to], n2[i + 1]);
    }

    for (int to : list[node])
        solve(to);
}



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n); need = n / 2;
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    dfs(1);
    solve(1);

    for (i = 1; i <= n; i++)
        printf("%d ", can_be[i]);

    return 0;
}