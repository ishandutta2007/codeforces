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

const int bits = 30;

struct rest {
    int l, r, q;
};

int n, m, i;
int ans[maxN];
rest R[maxN];

int sum[maxN];
int cnt[maxN];

void solve(int bit) {
    int i;

    memset(sum, 0, sizeof(sum));
    for (i = 1; i <= m; i++) {
        if ((R[i].q >> bit) & 1) {
            sum[R[i].l]++;
            sum[R[i].r + 1]--;
        }
    }

    for (i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
        if (sum[i]) ans[i] |= 1 << bit;

        cnt[i] = cnt[i - 1] + (sum[i] == 0 ? 1 : 0);
    }

    for (i = 1; i <= m; i++) {
        if ((R[i].q >> bit) & 1) continue;

        int act = cnt[R[i].r] - cnt[R[i].l - 1];
        if (act == 0) {
            printf("NO");
            exit(0);;
        }
    }
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++)
        scanf("%d%d%d", &R[i].l, &R[i].r, &R[i].q);

    for (int bit = 0; bit < bits; bit++)
        solve(bit);

    printf("YES\n");
    for (i = 1; i <= n; i++) printf("%d ", ans[i]);


    return 0;
}