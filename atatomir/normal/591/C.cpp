#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 500011

int n, i, j;
int v[maxN];
int sol[maxN];
bool good[maxN];

int ans = 0;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        sol[i] = v[i];
    }

    good[1] = good[n] = true;
    for (i = 2; i < n; i++) good[i] = (v[i] == v[i - 1]) || (v[i] == v[i + 1]);

    for (i = 1; i <= n; i++) {
        if (good[i])
            v[i] = 0;
        else
            v[i] = v[i - 1] + 1;

        ans = max(ans, v[i]);
    }

    printf("%d\n", (ans + 1) / 2);

    for (i = n; i > 0; i--) {
        if (v[i] == 0) continue;

        int l = i - v[i] + 1;
        int r = i;

        if ( (r - l + 1) % 2 == 0 ) {
            int mid = (l + (r - l + 1) / 2) - 1;
            for (j = l; j <= mid; j++) sol[j] = sol[l - 1];
            for (j = mid + 1; j <= r; j++) sol[j] = sol[r + 1];
        } else {
            for (j = l; j <= r; j++)
                sol[j] = sol[l - 1];
        }

        i = l;
    }

    for (i = 1; i <= n; i++) printf("%d ", sol[i]);

    return 0;
}