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

#define maxN 33

const ll defX[4] = {0, 0, -1, 1};
const ll defY[4] = {-1, 1, 0, 0};
const int nxt_gap[4] = {1, 0, 3, 2};

int n, i, x, y;
vector<int> list[maxN];
pair<ll, ll> sol[maxN];


void solve(int node, int root, ll x, ll y, ll delta, int busy) {
    sol[node] = {x, y};

    int gap = 0;
    for (auto to : list[node]) {
        if (to == root) continue;

        while ((1 << gap) == busy) gap++;
        solve(to, node, x + delta * defX[gap], y + delta * defY[gap], delta / 3, 1 << nxt_gap[gap]);
        gap++;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    for (i = 1; i <= n; i++) {
        if (list[i].size() > 4) {
            printf("NO");
            return 0;
        }
    }

    solve(1, 0, 0, 0, 1LL << 58, 0);

    printf("YES\n");
    for (i = 1; i <= n; i++)
        printf("%lld %lld\n", sol[i].first, sol[i].second);



    return 0;
}