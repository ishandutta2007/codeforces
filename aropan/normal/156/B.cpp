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


const int MAXN = 100007;

int a[MAXN];
int n, m, k, l;
int f[MAXN], g[MAXN];
int t[MAXN];

int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {   
        scanf("%d", &a[i]);
        (a[i] <= 0? g : f)[abs(a[i])]++;
        k += a[i] < 0;
    }

    for (int i = 1; i <= n; i++)
        if (f[i] + k - g[i] == m)
        {
            t[i] = true;
            l++;
        }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0 && t[a[i]] && l == 1 || a[i] < 0 && !t[-a[i]]) puts("Truth"); else
        if (a[i] > 0 && !t[a[i]] || a[i] < 0 && t[-a[i]] && l == 1) puts("Lie"); else
            puts("Not defined");
    }
    return 0;
}