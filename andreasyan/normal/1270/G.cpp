#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n;
int a[N];

int s, f;
int c[N];
int p[N];
bool dfs(int i)
{
    c[i] = 1;
    int h = i - a[i];
    if (c[h] == 0)
    {
        p[h] = i;
        if (dfs(h))
            return true;
    }
    if (c[h] == 1)
    {
        f = i;
        s = h;
        return true;
    }
    c[i] = 2;
    return false;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    dfs(1);
    vector<int> v;
    for (int i = f; i != s; i = p[i])
        v.push_back(i);
    v.push_back(s);
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}