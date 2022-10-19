#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n;
int a[N];

int s, f;
int p[N];
int c[N];
bool dfs(int x)
{
    c[x] = 1;
    if (c[a[x]] == 1)
    {
        s = a[x];
        f = x;
        c[x] = 2;
        return true;
    }
    if (c[a[x]] == 0)
    {
        p[a[x]] = x;
        if (dfs(a[x]))
        {
            c[x] = 2;
            return true;
        }
    }
    c[x] = 2;
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    vector<vector<int> > vv;
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            if (dfs(i))
            {
                vector<int> v;
                for (int x = f; x != s; x = p[x])
                    v.push_back(x);
                v.push_back(s);
                vv.push_back(v);
            }
        }
    }
    int r = 0;
    for (int i = 0; i < vv.size(); ++i)
    {
        if (vv[i].size() == 1)
        {
            r = vv[i][0];
            break;
        }
    }
    if (r)
    {
        printf("%d\n", vv.size() - 1);
    }
    else
    {
        printf("%d\n", vv.size());
    }
    for (int i = 0; i < vv.size(); ++i)
    {
        if (vv[i][0] == r)
            continue;
        if (r)
            a[vv[i][0]] = r;
        else
            a[vv[i][0]] = vv[0][0];
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}