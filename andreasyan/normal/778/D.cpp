#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 55;

int n, m;
char a[N][N], b[N][N];

vector<pair<int, int> > v;
void dfs(int x, int y)
{
    if (a[x][y + 1] == 'L' && a[x + 1][y + 1] == 'U')
    {
        dfs(x + 1, y + 1);
    }
    if (a[x][y + 1] == 'L' && a[x + 1][y + 1] == 'L')
    {
        v.push_back(m_p(x, y + 1));
        a[x][y + 1] = 'U';
        a[x + 1][y + 1] = 'D';
        a[x][y + 2] = 'U';
        a[x + 1][y + 2] = 'D';
    }
    if (a[x][y + 1] == 'U')
    {
        v.push_back(m_p(x, y));
        a[x][y] = 'L';
        a[x][y + 1] = 'R';
        a[x + 1][y] = 'L';
        a[x + 1][y + 1] = 'R';
    }
}

vector<pair<int, int> > ans;
void solv()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'U')
                dfs(i, j);
        }
    }
    ans = v;
    v.clear();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = b[i][j];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'U')
                dfs(i, j);
        }
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
        ans.push_back(v[i]);
}

char aa[N][N], bb[N][N];
int main()
{
    //no
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    if (m % 2 == 0)
    {
        solv();
    }
    else
    {
        for (int j = 0, ii = 0; j < m; ++j, ++ii)
        {
            for (int i = n - 1, jj = 0; i >= 0; --i, ++jj)
            {
                aa[ii][jj] = a[i][j];
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (aa[i][j] == 'L')
                    a[i][j] = 'U';
                if (aa[i][j] == 'R')
                    a[i][j] = 'D';
                if (aa[i][j] == 'U')
                    a[i][j] = 'R';
                if (aa[i][j] == 'D')
                    a[i][j] = 'L';
            }
            a[i][n] = '\0';
        }
        for (int j = 0, ii = 0; j < m; ++j, ++ii)
        {
            for (int i = n - 1, jj = 0; i >= 0; --i, ++jj)
            {
                bb[ii][jj] = b[i][j];
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (bb[i][j] == 'L')
                    b[i][j] = 'U';
                if (bb[i][j] == 'R')
                    b[i][j] = 'D';
                if (bb[i][j] == 'U')
                    b[i][j] = 'R';
                if (bb[i][j] == 'D')
                    b[i][j] = 'L';
            }
            b[i][n] = '\0';
        }
        swap(n, m);
        solv();
        swap(n, m);
        for (int i = 0; i < ans.size(); ++i)
        {
            //cout << ans[i].first << ' ' << ans[i].second << endl;
            swap(ans[i].first, ans[i].second);
            ans[i].first = (n - ans[i].first - 1 - 1);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    return 0;
}