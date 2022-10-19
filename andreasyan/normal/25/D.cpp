#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1003;

int n;
set<int> a[N];

bool c[N];
pair<int, int> dfs(int x, int p)
{
    c[x] = true;
    for (set<int>::iterator it = a[x].begin(); it != a[x].end(); ++it)
    {
        int h = *it;
        if (h == p)
            continue;
        if (c[h])
            return m_p(x, h);
        else
        {
            pair<int, int> t = dfs(h, x);
            if (t.first)
                return t;
        }
    }
    return m_p(0, 0);
}

bool cc[N];
void dfs0(int x)
{
    cc[x] = true;
    for (set<int>::iterator it = a[x].begin(); it != a[x].end(); ++it)
    {
        int h = *it;
        if (!cc[h])
            dfs0(h);
    }
}

vector<pair<pair<int, int>, pair<int, int> > > ans;
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].insert(y);
        a[y].insert(x);
    }
    while (1)
    {
        for (int i = 1; i <= n; ++i)
        {
            c[i] = false;
            cc[i] = false;
        }

        dfs0(1);
        pair<int, int> s = m_p(0, 0);
        for (int i = 1; i <= n; ++i)
            if (!cc[i])
            {
                s = m_p(1, i);
                break;
            }
        if (!s.first)
            break;

        for (int i = 1; i <= n; ++i)
        {
            if (!c[i])
            {
                pair<int, int> q = dfs(i, i);
                if (q.first)
                {
                    a[q.first].erase(q.second);
                    a[q.second].erase(q.first);
                    a[s.first].insert(s.second);
                    a[s.second].insert(s.first);
                    ans.push_back(m_p(q, s));
                    break;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first.first << ' ' << ans[i].first.second << ' ' << ans[i].second.first << ' ' << ans[i].second.second << endl;
    return 0;
}