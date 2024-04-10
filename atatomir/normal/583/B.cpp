#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 1024

int n, i, wh, ans;
int v[maxN];
bool dir;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);

    wh = 1; dir = 1;

    for (i = 0; i < n; i++) {
        if (dir == 1) {
            while (wh <= n && v[wh] > i) wh++;

            if (wh == n + 1) {
                dir ^= 1; wh--;
                i--;
                ans++;
                continue;
            }

            v[wh] = maxN;
        } else {
            while (wh > 0 && v[wh] > i) wh--;

            if (wh == 0) {
                dir ^= 1; wh++;
                i--;
                ans++;
                continue;
            }

            v[wh] = maxN;
        }
    }

    printf("%d", ans);

    return 0;
}