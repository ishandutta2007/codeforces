#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;


const int MAXX = 10000007;
int f[MAXX];
int n, a;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    for (int i = 1, x; (x = i * i) < MAXX; i++)
        for (int j = x; j < MAXX; j += x)
            f[j] = x;
    scanf("%d %d\n", &a, &n);

    long long ans = 0;
    for (int i = 0; i < n; i++, a++)
        ans += a / f[a];
    cout << ans << endl;
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}