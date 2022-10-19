#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 2003;

int n, m;
char a[N][N];
vector<pair<int, int> > v[26];

vector<pair<pair<int, int>, pair<int, int> > > ans;

bool stg1(int k)
{
    for (int i = 0; i < v[k].size(); ++i)
    {
        if (v[k][i].first != v[k][0].first)
            return false;
    }
    for (int j = v[k][0].second; j <= v[k].back().second; ++j)
    {
        if (a[v[k][0].first][j] == '.')
            return false;
        if (a[v[k][0].first][j] - 'a' < k)
            return false;
    }
    return true;
}

bool stg2(int k)
{
    for (int i = 0; i < v[k].size(); ++i)
    {
        if (v[k][i].second != v[k][0].second)
            return false;
    }
    for (int i = v[k][0].first; i <= v[k].back().first; ++i)
    {
        if (a[i][v[k][0].second] == '.')
            return false;
        if (a[i][v[k][0].second] - 'a' < k)
            return false;
    }
    return true;
}

bool solv()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int k = 0; k < 26; ++k)
        v[k].clear();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] != '.')
                v[a[i][j] - 'a'].push_back(m_p(i, j));
        }
    }
    ans.clear();
    for (int k = 0; k < 26; ++k)
    {
        if (v[k].empty())
        {
            for (int i = k + 1; i < 26; ++i)
            {
                if (!v[i].empty())
                {
                    ans.push_back(m_p(v[i][0], v[i][0]));
                    break;
                }
            }
            continue;
        }
        if (stg1(k))
            ans.push_back(m_p(v[k][0], v[k].back()));
        else if (stg2(k))
            ans.push_back(m_p(v[k][0], v[k].back()));
        else
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
    {
        if (solv())
        {
            cout << "YES" << endl;
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); ++i)
            {
                cout << ans[i].first.first + 1 << ' ' << ans[i].first.second + 1 << ' ' << ans[i].second.first + 1 << ' ' << ans[i].second.second + 1 << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}