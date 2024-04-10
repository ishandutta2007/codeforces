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

#define maxN 200011

int hlog[maxN];

struct rmq {
    int n, llog, i, j;
    int *from;
    vector< vector<int> > data;

    void init(int _n, int *_from) {
        n = _n; from = _from;
        llog = hlog[n];
        data = vector< vector<int> >(llog + 2, vector<int>(n + 3, 0));

        for (i = 1; i <= n; i++) data[0][i] = from[i];
        for (i = 1; i <= llog; i++)
            for (j = 1; j + (1 << i) - 1 <= n; j++)
                data[i][j] = max(data[i - 1][j], data[i - 1][j + (1 << (i - 1))]);
    }

    int query(int l, int r) {
        int hp = hlog[r - l + 1];
        return max(data[hp][l], data[hp][r - (1 << hp) + 1]);
    }
};

int n, i;
int a[maxN], b[maxN];
rmq maxi, mini;

ll ans;

int bs(int x) {
    int ans = i - 1;

    for (int step = (1 << 17); step > 0; step >>= 1)
        if (ans + step <= n)
            if ( maxi.query(i, ans + step) + mini.query(i, ans + step) <= x)
                ans += step;

    return ans;
}



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++) scanf("%d", &b[i]), b[i] = -b[i];

    hlog[1] = 0;
    for (i = 2; i <= n; i++)
        hlog[i] = hlog[i - 1] + ( (1 << (hlog[i - 1] + 1)) == i ? 1 : 0 );

    maxi.init(n, a);
    mini.init(n, b);

    for (i = n; i >= 1; i--) {
        int p1 = bs(-1);
        int p2 = bs(0);

        ans += 1LL * (p2 - p1);
    }

    printf("%lld", ans);

    return 0;
}