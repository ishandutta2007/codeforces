#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vn, vm;

vector<int> to7(int x)
{
    vector<int> v;
    if (x == 0)
        v.push_back(0);
    while (x)
    {
        v.push_back((x % 7));
        x /= 7;
    }
    return v;
}

int main()
{
    scanf("%d%d", &n, &m);
    vn = to7(n - 1);
    vm = to7(m - 1);
    if (vn.size() + vm.size() > 7)
    {
        printf("0\n");
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            bool z = true;
            bool c[7] = {};
            vector<int> v = to7(i);
            while (v.size() < vn.size())
                v.push_back(0);
            for (int k = 0; k < v.size(); ++k)
            {
                if (c[v[k]])
                {
                    z = false;
                    break;
                }
                c[v[k]] = true;
            }
            if (!z)
                continue;
            v = to7(j);
            while (v.size() < vm.size())
                v.push_back(0);
            for (int k = 0; k < v.size(); ++k)
            {
                if (c[v[k]])
                {
                    z = false;
                    break;
                }
                c[v[k]] = true;
            }
            if (!z)
                continue;
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}