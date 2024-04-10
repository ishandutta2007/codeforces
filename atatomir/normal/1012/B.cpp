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

const int maxN = 400011;

ll n, m, q, i, x, y, cnt;
vector<int> list[maxN];
bool us[maxN];

void dfs(int node) {
    us[node] = true;
    for (auto e : list[node])
        if (!us[e])
            dfs(e);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> m >> q;
    for (i = 1; i <= q; i++) {
        cin >> x >> y;
        list[x].pb(n + y);
        list[n + y].pb(x);
    }

    for (i = 1; i <= n + m; i++) {
        if (us[i]) continue;
        dfs(i);
        cnt++;
    }

    cout << cnt - 1;


    return 0;
}