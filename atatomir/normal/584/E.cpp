#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 2015

int n, i, x, pos, ind;
int perm[maxN], wh[maxN];
int coin;

vector< pair<int, int> > ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &perm[i]);

    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        wh[x] = i;
    }
    for (i = 1; i <= n; i++) perm[i] = wh[ perm[i] ];

    while (n > 0) {
        for (pos = 1; perm[pos] != n; pos++) ;

        ind = 0;
        while (pos < n) {
            ind = max(ind, pos + 1);
            while (perm[ind] > pos) ind++;

            coin += ind - pos;
            ans.pb(mp(pos, ind));
            swap(perm[ind], perm[pos]);
            pos = ind;
        }

        n--;
    }

    printf("%d\n%d\n", coin, ans.size());
    for (auto who : ans) printf("%d %d\n", who.first, who.second);

    return 0;
}