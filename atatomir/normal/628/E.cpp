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

#define maxN 3014

int n, m, i, j;
char mat[maxN][maxN];
int w[maxN][maxN], e[maxN][maxN];
int sw[maxN][maxN];

vector< pair<int, int> > event;
int aib[maxN];

ll ans;


int zrs(int x) {
    return (x ^ (x - 1)) & x;
}

void add(int x, int v) {
    while (x <= n) {
        aib[x] += v;
        x += zrs(x);
    }
}

int sum(int x) {
    int ans = 0;

    while (x > 0) {
        ans += aib[x];
        x -= zrs(x);
    }

    return ans;
}

void solve(int x, int y) {
    int i, pos, xx, yy;

    event.clear(); pos = 0;
    memset(aib, 0, sizeof(aib));

    xx = x; yy = y;
    for (i = 1; x <= n && y > 0; i++, x++, y--) {
        if (mat[x][y] != 'z') continue;
        event.pb(mp(i + min(w[x][y], sw[x][y]), i));
    }

    x = xx; y = yy;
    sort(event.begin(), event.end());

    for (i = 1; x <= n && y > 0; i++, x++, y--) {
        while (pos < event.size()) {
            if (event[pos].first > i) break;
            add(event[pos++].second, -1);
        }

        if (mat[x][y] != 'z') continue;

        add(i, +1);
        ans += sum(i) - sum(i - e[x][y]);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n", &n, &m);
    for (i = 1; i <= n; i++) scanf("%s\n", mat[i] + 1);

    for (i = n; i > 0; i--) {
        for (j = 1; j <= m; j++)
            w[i][j] = (mat[i][j] == 'z' ? 1 + w[i][j - 1] : 0);
        for (j = m; j > 0; j--)
            e[i][j] = (mat[i][j] == 'z' ? 1 + e[i][j + 1] : 0);

        for (j = 1; j <= m; j++)
            sw[i][j] = (mat[i][j] == 'z' ? 1 + sw[i + 1][j - 1] : 0);
    }

    for (i = 1; i <= m; i++)
        solve(1, i);
    for (i = 2; i <= n; i++)
        solve (i, m);

    printf("%lld", ans);

    return 0;
}