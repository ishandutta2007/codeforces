#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];
int b[N];

vector<vector<int> > vv;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (b[i])
            continue;
        vector<int> v;
        int x = i;
        while (1)
        {
            v.push_back(x);
            if (a[x] == 0)
                break;
            x = a[x];
        }
        vv.push_back(v);
    }
    for (int i = 0; i < (int)vv.size() - 1; ++i)
    {
        a[vv[i].back()] = vv[i + 1][0];
    }
    if (!vv.empty())
    {
        a[vv.back().back()] = vv[0][0];
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}