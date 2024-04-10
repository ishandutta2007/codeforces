#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 500009;
vector<int> g[MAX_N];
bool c[MAX_N];

bool check(int v, int pr)
{
    if (g[v].size() >= 4 || (c[v] && g[v].size() == 3))
        return true;
    int cnt = 0;
    if (g[v].size() == 3)
    {
        for (int to : g[v])
        {
            if (c[to])
                return true;
            if (g[to].size() > 1)
                cnt++;
        }
    }
    if (cnt >= 2)
        return true;
    for (int to : g[v])
    {
        if (to == pr)
            continue;
        if (check(to, v))
            return true;
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
            c[i] = (s[i] == 'W');
        if (check(0, -1))
            cout << "White\n";
        else
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (g[i].size() == 1)
                    cnt++;
            }
            if (cnt == 4)
            {
                bool u = false;
                for (int i = 0; i < n; i++)
                {
                    if (c[i])
                        u = true;
                }
                if (n % 2 == 1)
                    u = true;
                if (u)
                    cout << "White\n";
                else
                    cout << "Draw\n";
            }
            else
            {
                int u = 0;
                int k = 0;
                int len = n;
                for (int i = 0; i < n; i++)
                {
                    if (c[i] && g[i].size() >= 2)
                        u++;
                    if (c[i] && g[i].size() == 1)
                        k++;
                }
                if (cnt == 3)
                {
                    k++;
                    len -= 3;
                }
                if ((u && (n >= 4 || (n == 3 && u + k >= 2))) || (k >= 2 && len % 2 == 1))
                    cout << "White\n";
                else
                    cout << "Draw\n";
            }
        }
        for (int i = 0; i < n; i++)
            g[i].resize(0);
    }
}