#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 1000000007;

int n;
int a[N];

int c[N], p[N];
int s, f;
bool dfs(int x)
{
    c[x] = 1;
    if (c[a[x]] == 0)
    {
        p[a[x]] = x;
        if (dfs(a[x]))
        {
            c[x] = 2;
            return true;
        }
    }
    if (c[a[x]] == 1)
    {
        s = a[x];
        f = x;
        c[x] = 2;
        return true;
    }
    c[x] = 2;
    return false;
}

int erk[N];
vector<int> v;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            if (dfs(i))
            {
                int q = 0;
                for (int x = f; x != s; x = p[x])
                    ++q;
                ++q;
                v.push_back(q);
            }
        }
    }

    erk[0] = 1;
    for (int i = 1; i <= n; ++i)
        erk[i] = (2 * erk[i - 1]) % M;

    int qq = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        qq += v[i];
    }

    long long ans = erk[n - qq];
    for (int i = 0; i < v.size(); ++i)
    {
        ans *= (erk[v[i]] - 2 + M);
        ans %= M;
    }

    cout << ans << endl;
    return 0;
}