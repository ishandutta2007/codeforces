#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int n = 7;
struct ban
{
    int x;
    int i;
    char t;
    ban(){}
    ban(int x, int i, char t)
    {
        this->x = x;
        this->i = i;
        this->t = t;
    }
};

vector<ban> a[n];

bool c[n];
void dfs(int x)
{
    c[x] = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].x;
        if (!c[h])
            dfs(h);
    }
}

bool cc[n][102];

vector<pair<int, char> > ans;

void dfs1(int x, pair<int, char> p)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        ban h = a[x][i];
        if (!cc[x][h.i])
        {
            cc[x][h.i] = true;
            cc[h.x][h.i] = true;
            if (h.t == '-')
                dfs1(h.x, m_p(h.i, '+'));
            else
                dfs1(h.x, m_p(h.i, '-'));
        }
    }
    if(p.first != -1)
        ans.push_back(p);
}

int main()
{
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(ban(y, i, '+'));
        a[y].push_back(ban(x, i, '-'));
    }
    for (int i = 0; i < n; ++i)
    {
        if (!a[i].empty())
        {
            dfs(i);
            break;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (!c[i] && !a[i].empty())
        {
            cout << "No solution" << endl;
            return 0;
        }
    }
    vector<int> k;
    for (int i = 0; i < n; ++i)
    {
        if (a[i].size() % 2 == 1)
            k.push_back(i);
    }
    if (k.size() == 1 || k.size() > 2)
    {
        cout << "No solution" << endl;
        return 0;
    }
    if (!k.empty())
        dfs1(k[0], m_p(-1, '-'));
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (!a[i].empty())
            {
                dfs1(i, m_p(-1, '-'));
                break;
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}