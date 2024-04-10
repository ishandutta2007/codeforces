#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <assert.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 400055
#define inf 1000000000

const int def = 200020;

int n, i, x, y, tp;
int down[maxN], up[maxN], le[maxN], ri[maxN];
ll ans;

void upd_max(int& a, int b) {
    if (b > a) a = b;
}

void upd_min(int& a, int b) {
    if (b < a) a = b;
}

int main()
{
  //  freopen("test.in","r",stdin);

    for (i = 0; i <= 2 * def + 4; i++) {
        up[i] = ri[i] = inf;
        down[i] = le[i] = -inf;
    }


    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);
        x += 100004;
        y += 100004;

        assert(def + x - y >= 10 && def + x - y < maxN - 10);

        y--;
        upd_max(down[def + x - y], y);
        y++;

        x--;
        upd_max(le[def + x - y], y);
        x++;

        x++;
        upd_min(ri[def + x - y], y);
        x--;

        y++;
        upd_min(up[def + x - y], y);
        y--;
    }

    for (i = 2; i <= 2 * def; i++) {
        upd_max(down[i], down[i - 2] - 1);
        upd_min(ri[i], ri[i - 2] - 1);
    }

    for (i = 2 * def; i >= 0; i--) {
        upd_max(le[i], le[i + 2] + 1);
        upd_min(up[i], up[i + 2] + 1);
    }

    for (i = 1; i <= 2 * def; i++) {
        int p1 = max(up[i], ri[i]);
        int p2 = min(down[i], le[i]);

        if (p1 <= p2)
            ans += (1LL * (p2 - p1 + 1)) ;
    }

    cout << ans;


    return 0;
}