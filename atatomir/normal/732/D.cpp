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

int n, m, i;
int d[maxN];
int a[maxN];

bool solved[maxN];

bool check(int last) {
    int i, rez;

    memset(solved, 0, sizeof(solved));
    solved[0] = true;
    rez = 0;

    for (i = last; i > 0; i--) {
        if (solved[d[i]]) { // use it to study
            rez = max(0, rez - 1);
        } else { // use it to pass
            solved[d[i]] = true;
            rez += a[d[i]];
        }
    }

    if (rez > 0) return false;

    for (i = 1; i <= m; i++)
        if (solved[i] == false)
            return false;

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%d", &d[i]);
    for (i = 1; i <= m; i++) scanf("%d", &a[i]);

    int ans = 0;
    for (int step = (1 << 17); step > 0; step >>= 1)
        if (ans + step <= n)
            if (!check(ans + step))
                ans += step;

    ans++;
    if (ans > n) {
        printf("-1");
        return 0;
    }

    printf("%d", ans);


    return 0;
}