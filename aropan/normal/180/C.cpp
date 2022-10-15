#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100007;

int a[MAXN];
char s[MAXN];
int n, m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    gets(s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    	a[i] = a[i - 1] + ('A' <= s[i] && s[i] <= 'Z');
    int ans = n;
    for (int i = 0; i <= n; i++)
    	ans = min(ans, i - a[i] + a[n] - a[i]);
    printf("%d\n", ans);
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}