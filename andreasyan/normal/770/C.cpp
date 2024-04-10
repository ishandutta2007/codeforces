#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, k;
bool u[N];
vector<int> a[N];

vector<int> v;
int c[N];
bool dfs(int x)
{
    c[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (c[h] == 1)
            return true;
        if (!c[h])
            if (dfs(h))
                return true;
    }
    c[x] = 2;
    v.push_back(x);
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    while (k--)
    {
        int x;
        cin >> x;
        u[x] = true;
    }
    for (int x = 1; x <= n; ++x)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int y;
            cin >> y;
            a[x].push_back(y);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i] && u[i])
        {
            if (dfs(i))
            {
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}