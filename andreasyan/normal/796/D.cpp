#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n, kk, dd;
bool u[N];
pair<int, int> b[N];
vector<int> a[N];

int c[N];
int main()
{
    cin >> n >> kk >> dd;
    while (kk--)
    {
        int x;
        cin >> x;
        u[x] = true;
    }
    for (int i = 1; i < n; ++i)
    {
        cin >> b[i].first >> b[i].second;
        a[b[i].first].push_back(b[i].second);
        a[b[i].second].push_back(b[i].first);
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (u[i])
        {
            q.push(i);
            c[i] = i;
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (!c[h])
            {
                q.push(h);
                c[h] = c[x];
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i < n; ++i)
    {
        if (c[b[i].first] != c[b[i].second])
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    return 0;
}