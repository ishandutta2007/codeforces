#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

const int N = 5100;

int a[N][N];
int d[N][N];


int main() {
#ifdef amit_swami
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[0][i]);
    for (int k = 1; k < n; k++) forn(i, n) a[k][i] = a[k - 1][i] ^ a[k - 1][i + 1];
    for (int l = n - 1; l >= 0; l--) for (int r = l + 1; r <= n; r++)
    {
        d[l][r] = a[r - l - 1][l];
        if (r - l > 1) d[l][r] = max(d[l][r], max(d[l + 1][r], d[l][r - 1]));
    }
    int q;
    scanf("%d", &q);
    forn(i, q)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        printf("%d\n", d[l][r]);
    }


    return 0;
}