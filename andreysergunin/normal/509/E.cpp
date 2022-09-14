#include <bits/stdc++.h>
#define sqr(a) ((a) * (a))

using namespace std;
const int MAXN = 1000000;
const int INF = 1000000000;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char s[MAXN];
    scanf("%s", s);
    int n = strlen(s);
    double p[MAXN];
    p[1] = 1;
    for (int i = 2; i <= n; i++)
        p[i] = p[i - 1] + (double) 1 / i;
    double a[MAXN];
    a[0] = p[n];
    for (int i = 1; i < n; i++)
        a[i] = (double) a[i - 1] - p[i] + p[n - i];
    double ans = 0;;
    for (int i = 0; i < n; i++)
        if (s[i] == 'I' || s[i] == 'E' || s[i] == 'A' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
            ans += a[i];
    printf("%.9lf\n", ans);
}