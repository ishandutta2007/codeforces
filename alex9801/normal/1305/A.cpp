#include <bits/stdc++.h>
using namespace std;

int a[110];
int b[110];

void solve()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    sort(a, a + n);
    sort(b, b + n);

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    puts("");
    for(int i = 0; i < n; i++)
        printf("%d ", b[i]);
    puts("");
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, i;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        solve();

    return 0;
}