#include <bits/stdc++.h>
using namespace std;
const int N = 500005;

int n, m;
vector<int> a[N];
vector<int> b[N];

int k;
int c[N];
bool cc[N];
void dfs(int x)
{
    c[x] = k;
    for (int i = 0; i < b[x].size(); ++i)
    {
        int hh = b[x][i];
        if (cc[hh])
            continue;
        cc[hh] = true;
        for (int j = 0; j < a[hh].size(); ++j)
        {
            int h = a[hh][j];
            if (!c[h])
                dfs(h);
        }
    }
}

int q[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
            b[x].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            ++k;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i)
        q[c[i]]++;
    for (int i = 1; i <= n; ++i)
        cout << q[c[i]] << ' ';
    cout << endl;
    return 0;
}