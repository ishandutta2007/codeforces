#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

const int N = 110000;

int a[N];


int main()
{
    #ifdef amit_swami
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    int n, z;
    scanf("%d%d", &n, &z);        
    forn(i, n) scanf("%d", &a[i]);
    int j = 0;
    double res = -1;
    forn(i, n)
    {
        while (j < n && a[j] - a[i] <= z) ++j;
        int I = i, J = i + 1, K = j - 1;
        if (J < K)
        {
            res = max(res, (a[K] - a[J]) * 1. / (a[K] - a[I]));
        }
    }
    if (res < -0.5) printf("-1\n");
    else printf("%.10f\n", res);
    return 0;
}