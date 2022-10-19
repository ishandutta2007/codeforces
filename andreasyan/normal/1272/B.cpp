#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
char a[N];

int b[N];

int m;
char ans[N];

void solv()
{
    scanf(" %s", a);
    n = strlen(a);
    b['U'] = b['D'] = b['L'] = b['R'] = 0;
    for (int i = 0; i < n; ++i)
    {
        b[a[i]]++;
    }
    int y = min(b['U'], b['D']);
    int x = min(b['L'], b['R']);
    if (y == 0)
        x = min(x, 1);
    if (x == 0)
        y = min(y, 1);
    m = 0;
    for (int i = 0; i < y; ++i)
        ans[m++] = 'U';
    for (int i = 0; i < x; ++i)
        ans[m++] = 'R';
    for (int i = 0; i < y; ++i)
        ans[m++] = 'D';
    for (int i = 0; i < x; ++i)
        ans[m++] = 'L';
    ans[m] = 0;
    printf("%d\n", m);
    printf("%s\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}