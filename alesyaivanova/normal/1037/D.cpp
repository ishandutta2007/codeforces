#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200010;
int n;
vector<int> g[MAX_N];
int a[MAX_N];
int p[MAX_N];
int pr[MAX_N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    p[0] = 1;
    pr[0] = -1;
    p[1] = p[0] + (int)g[a[0]].size();
    for (int e = p[0]; e < p[1]; e++)
        pr[e] = 0;
    for (int i = 2; i < n; i++)
    {
        p[i] = p[i - 1] + (int)g[a[i - 1]].size() - 1;
        for (int e = p[i - 1]; e < p[i]; e++)
            pr[e] = a[i - 1];
    }
    for (int i = 0; i < n; i++)
        sort(g[i].begin(), g[i].end());
    for (int i = 0; i < n - 1; i++)
        sort(a + p[i], a + p[i + 1]);
    bool u = true;
    if (a[0] != 0)
        u = false;
    p[n] = n;
    for (int i = 0; i < n; i++)
    {
        for (int e = p[i], j = 0; e < p[i + 1]; e++, j++)
        {
            if (a[e] != g[pr[e]][j])
            {
                if (g[pr[e]][j] == pr[i])
                    e--;
                else
                    u = false;
            }
        }
    }
    if (u)
        cout << "Yes";
    else
        cout << "No";
}