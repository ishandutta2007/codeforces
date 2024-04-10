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

const int MAXL = 5007;

int n, m;
char a[MAXL], b[MAXL];

int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    n = strlen(a + 1);
    m = strlen(b + 1);
    int ans = m;
    for (int i = -m; i <= n + 1; i++)
    {
        int c = 0;
        for (int j = 1; j <= m; j++)
        {
            int x = i + j - 1;
            if (1 <= x && x <= n && a[x] == b[j]) c++;
        }
        ans = min(ans, m - c);
    }
    printf("%d\n", ans);
    return 0;
}