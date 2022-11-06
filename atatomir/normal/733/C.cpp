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

#define maxN 555

int n, m, i, j, p1, p2, pos;
int a[maxN], b[maxN], sum[maxN];

int biggest;
pair<int, int> best;

vector< pair<int, char> > sol;

void no_sol() {
    printf("NO");
    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
    scanf("%d", &m);
    for (i = 1; i <= m; i++) scanf("%d", &b[i]);

    p1 = 1;
    for (i = 1; i <= m; i++) {
        p2 = p1;
        while (p2 <= n && sum[p2] - sum[p1 - 1] < b[i]) p2++;

        if (p2 > n) no_sol();
        if (sum[p2] - sum[p1 - 1] != b[i]) no_sol();

        if (p1 == p2) {
            p1 = p2 + 1;
            continue;
        }

        biggest = -1;
        best = mp(-1, -1);
        for (j = p1; j <= p2; j++) {
            biggest = max(biggest, a[j]);
            if (j != p1 && a[j] > a[j - 1])
                best = max(best, mp(a[j], j));
            if (j != p2 && a[j] > a[j + 1])
                best = max(best, mp(a[j], j));
        }

        if (best.first != biggest) no_sol();
        pos = best.second;

        if (pos != p2 && a[pos] > a[pos + 1]) {
            for (j = pos + 1; j <= p2; j++) sol.pb(mp(pos - p1 + i, 'R'));
            for (j = pos; j > p1; j--) sol.pb(mp(j - p1 + i, 'L'));
        } else {
            for (j = pos; j > p1; j--) sol.pb(mp(j - p1 + i, 'L'));
            for (j = pos + 1; j <= p2; j++) sol.pb(mp(i, 'R'));
        }

        p1 = p2 + 1;
    }

    if (p1 != n + 1) no_sol();

    printf("YES\n");
    for (auto e : sol)
        printf("%d %c\n", e.first, e.second);


    return 0;
}