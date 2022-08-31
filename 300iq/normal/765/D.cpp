#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> f(n + 1), g(n + 1), h(n + 1, -1);
    vector <int> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        t.push_back(f[i]);
        g[i] = f[i];
    }
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());
    for (int i = 1; i <= n; i++)
    {
        g[i] = lower_bound(t.begin(), t.end(), f[i]) - t.begin() + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        h[g[i]] = f[i];
    }
    int m = n + 1;
    for (int i = 1; i <= n; i++)
    {
        if (h[i] == -1)
        {
            m = i;
            break;
        }
        if ((h[g[i]] != -1 && h[g[i]] != f[i]) || (h[i] != -1 && g[h[i]] != i))
        {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << m - 1 << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << g[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i < m; i++)
    {
        cout << h[i] << ' ';
    }
    cout << '\n';
}