#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n;
vector<pair<int, int > > a[N];

int yans;
void dfs0(int x, int p)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        if (a[x][i].second == 0)
            ++yans;
        dfs0(h, x);
    }
}

int ans[N];
void dfs(int x, int p)
{
    ans[x] = yans;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        if (a[x][i].second == 0)
            --yans;
        else
            ++yans;
        dfs(h, x);
        if (a[x][i].second == 0)
            ++yans;
        else
            --yans;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(m_p(y, 1));
        a[y].push_back(m_p(x, 0));
    }
    dfs0(1, 1);
    dfs(1, 1);
    int minu = N;
    for (int i = 1; i <= n; ++i)
        minu = min(minu, ans[i]);
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i] == minu)
            v.push_back(i);
    }
    cout << ans[v[0]] << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}