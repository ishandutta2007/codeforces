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

int n, i, dim, v, wh[maxN];
int a[maxN], sol[2][maxN];
vector< pair<int, int> > ord;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]), ord.pb(mp(a[i], i));
    sort(ord.begin(), ord.end());
    for (i = 1; i <= n; i++) a[i] = ord[i - 1].first, wh[ ord[i - 1].second ] = i;

    if (n == 1) {
        printf("YES\n0\n%d", a[1]);
        return 0;
    }

    dim = (n + 2) / 3;
    for (i = 1; i <= dim; i++) {
        sol[0][i] = i - 1;
        sol[1][i] = a[i] - (i - 1);
    }

    for (i = dim + 1; i <= 2 * dim; i++) {
        sol[1][i] = i - 1;
        sol[0][i] = a[i] - (i - 1);
    }

    v = dim - 1;
    for (i = 2 * dim + 1; i <= n; i++, v--) {
        sol[1][i] = v;
        sol[0][i] = a[i] - v;
    }

    printf("YES\n");
    for (i = 1; i <= n; i++) printf("%d ", sol[0][ wh[i] ]); printf("\n");
    for (i = 1; i <= n; i++) printf("%d ", sol[1][ wh[i] ]);




    return 0;
}