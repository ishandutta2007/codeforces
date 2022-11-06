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

int n, m, i, j, k, x;
vector<int> data[maxN];
int tp[maxN];
vector<int> ans;
vector<int> list[maxN][2];

bool us[maxN];

void no_sol() {
    printf("No");
    exit(0);
}

void make_smaller(vector<int>& a, vector<int>& b) {
    int sz;
    int limit = min(a.size(), b.size());

    for (sz = 0; sz < limit; sz++)
        if (a[sz] != b[sz])
            break;

    if (sz == limit) {
        if (a.size() > b.size())
            no_sol();
    } else {
        if (a[sz] < b[sz]) {
            list[a[sz]][0].pb(b[sz]);
            list[b[sz]][1].pb(a[sz]);
        } else {
            tp[a[sz]] |= 2;
            tp[b[sz]] |= 1;
        }
    }
}

void dfs(int node) {
    us[node] = true;
    if (tp[node] == 1) {
        for (auto to : list[node][0]) {
            if ( (tp[to] |= 1) == 3 ) no_sol();
            if (!us[to]) dfs(to);
        }
    } else {
        ans.pb(node);
        for (auto to : list[node][1]) {
            if ( (tp[to] |= 2) == 3 ) no_sol();
            if (!us[to]) dfs(to);
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &k);
        for (j = 1; j <= k; j++) {
            scanf("%d", &x);
            data[i].pb(x);
        }
    }

    for (i = 1; i < n; i++)
        make_smaller(data[i], data[i + 1]);

    for (i = 1; i <= m; i++) {
        if (us[i]) continue;
        if (tp[i] == 0) continue;
        if (tp[i] == 3) no_sol();


        dfs(i);
    }

    sort(ans.begin(), ans.end());
    printf("Yes\n%d\n", ans.size());
    for (auto e : ans) printf("%d ", e);


    return 0;
}