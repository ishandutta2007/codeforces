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

#define maxN 333
#define mpp(a,b,c) mp(a,mp(b, c))
#define inf 2000000000

int n, m, p, i, j, x, l, r, last;
vector< pair<int, pair<int, int> > > work;
int dp[maxN * maxN];

int dist(const pair<int, int> &a, const pair<int, int> &b) {
    static int aa, bb;
    aa = a.first - b.first;
    bb = a.second - b.second;
    return (aa < 0 ? -aa : aa) + (bb < 0 ? -bb : bb);
}

int cb(int l, int r, pair<int, int> src) {
    int mid, rs;
    rs = r;

    while (l <= r) {
        mid = (l + r) >> 1;
        if (work[mid].second <= src)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return min(l, rs);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &p);
    work.pb(mpp(0, 1, 1));
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%d", &x), work.pb(mpp(x, i, j));

    sort(work.begin(), work.end());
    work.pb(mpp(0, 0, 0));

    dp[0] = 0; last = 0;
    for (i = 1; i <= n * m; i = r + 1, last = l) {
        l = r = i;

        while (r + 1 <= n * m && work[r + 1].first == work[l].first) r++;

        for (j = l; j <= r; j++) {
            dp[j] = inf;

            int aux = last;
            for (int row = 1; row <= n; row++) {
                int pos = cb(aux, l - 1, mp(row, work[j].second.second));
                aux = pos;

                if (pos > 0)
                    if (work[pos - 1].first + 1 == work[l].first)
                        dp[j] = min(dp[j], dp[pos - 1] + dist(work[pos - 1].second, work[j].second));

                if (work[pos].first + 1 == work[l].first)
                    dp[j] = min(dp[j], dp[pos] + dist(work[pos].second, work[j].second));
            }
        }
    }

    printf("%d", dp[n * m]);

    return 0;
}