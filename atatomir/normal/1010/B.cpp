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

const int maxN = 111;

int n, m, i, q, lo, hi, mid;
int p[maxN];

int ask(int x) {
    printf("%d\n", x);
    fflush(stdout);
    scanf("%d", &x);
    if (x == 0) exit(0);
    return x;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &m, &n);
    for (i = 1; i <= n; i++)
        p[i] = ask(1);

    q = 1;
    lo = 1;
    hi = m;

    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if ( (ask(mid) * p[q]) == -1 )
            hi = mid - 1;
        else
            lo = mid + 1;

        q++;
        if (q == n + 1) q = 1;
    }

    ask(lo);



    return 0;
}