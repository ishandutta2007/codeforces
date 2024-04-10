#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2003;
const int M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n, k;
int a[N];

int u[N];

vector<int> va[N], vb[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
    {
        if (k == 0)
        {
            if (i == 0)
                u[i] = 1;
            continue;
        }
        u[i] = 1;
        for (int j = (k - 1 + i); j >= (k - 1 + i) - i + 1; --j)
            u[i] = (u[i] * 1LL * j) % M;
        int f = 1;
        for (int j = 1; j <= i; ++j)
            f = (f * 1LL * j) % M;
        u[i] = (u[i] * 1LL * ast(f, M - 2)) % M;
    }
    for (int i = 1; i <= n; ++i)
    {
        int yans = 0;
        for (int j = i; j >= 1; --j)
        {
            yans = (yans + u[i - j] * 1LL * a[j]) % M;
        }
        printf("%d ", yans);
    }
    printf("\n");
    return 0;
    for (int i = 0; i <= n; ++i)
        va[i].assign(n, 0);
    for (int i = 1; i <= n; ++i)
    {
        va[i][i - 1] = 1;
    }
    for (int i = 0; i <= n; ++i)
        vb[i].assign(n, 0);
    for (int j = 0; j < k; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < n; ++j)
                vb[i][j] = vb[i - 1][j] + va[i][j];
        }
        for (int i = 0; i <= n; ++i)
            va[i] = vb[i];
        for (int j = 0; j < n; ++j)
            printf("%d ", va[n][j]);
        printf("\n");
    }
    return 0;
}
/*
10
1 1 1 1 1 1 1 1 1 1
10 9 8 7 6 5 4 3 2 1
55 45 36 28 21 15 10 6 3 1
220 165 120 84 56 35 20 10 4 1
715 495 330 210 126 70 35 15 5 1
2002 1287 792 462 252 126 56 21 6 1
5005 3003 1716 924 462 210 84 28 7 1
11440 6435 3432 1716 792 330 120 36 8 1
24310 12870 6435 3003 1287 495 165 45 9 1
48620 24310 11440 5005 2002 715 220 55 10 1
92378 43758 19448 8008 3003 1001 286 66 11 1
167960 75582 31824 12376 4368 1365 364 78 12 1
293930 125970 50388 18564 6188 1820 455 91 13 1
497420 203490 77520 27132 8568 2380 560 105 14 1
817190 319770 116280 38760 11628 3060 680 120 15 1
1307504 490314 170544 54264 15504 3876 816 136 16 1
2042975 735471 245157 74613 20349 4845 969 153 17 1
3124550 1081575 346104 100947 26334 5985 1140 171 18 1
4686825 1562275 480700 134596 33649 7315 1330 190 19 1
6906900 2220075 657800 177100 42504 8855 1540 210 20 1
*/