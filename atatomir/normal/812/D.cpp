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

int n, m, k, q, i, x, y;
vector<int> list[maxN];
int last[maxN];
bool any[maxN];

int cnt, down[maxN], l[maxN], r[maxN];

void dfs(int node) {
    l[node] = ++cnt;
    down[node] = 1;

    for (auto to : list[node]) {
        dfs(to);
        down[node] += down[to];
    }

    r[node] = cnt;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> m >> k >> q;
    for (i = 1; i <= k; i++) {
        cin >> x >> y;
        if (last[y] != 0)
            list[last[y]].pb(x), any[x] = true;
        last[y] = x;
    }

    for (i = 1; i <= n; i++)
        if (!any[i])
            dfs(i);

    for (i = 1; i <= q; i++) {
        cin >> x >> y;

        if (last[y] == 0) {
            cout << "0\n";
        } else {
            if (l[x] <= l[last[y]] && l[last[y]] <= r[x])
                cout << down[x] << '\n';
            else
                cout << "0\n";
        }
    }

    return 0;
}