#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 102;

int n, m;

vector<pair<int, int> > ans[N];

int main()
{
    cin >> n >> m;
    int z = 1;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        ans[x].push_back(m_p(x, z));
        ans[y].push_back(m_p(y, z));
        ++z;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i].empty())
        {
            ans[i].push_back(m_p(i, z));
            ++z;
        }
        cout << ans[i].size() << endl;
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j].first << ' ' << ans[i][j].second << endl;
    }
    return 0;
}