#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;


const int MAXN = 102;
const int MAXS = 2607;
const int MOD = 1000000007;

char c[MAXN];
int f[MAXN][MAXS];

inline void add(int &x, int d)
{
    x += d;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}

int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    f[0][0] = 1;
    for (int i = 1; i < MAXN; i++)
        for (int j = 0; j < MAXS; j++)
            for (int x = 0; x < 26 && x <= j; x++)
                add(f[i][j], f[i - 1][j - x]);

    int t;
    scanf("%d\n", &t);

    while (t--)
    {
        scanf("%s\n", c + 1);
        int n = strlen(c + 1);
        int m = 0;
        
        for (int i = 1; i <= n; i++)
            m += (c[i] -= 'a');
        int ans = f[n][m];
        add(ans, -1);
        printf("%d\n", ans);
    }
    return 0;
}