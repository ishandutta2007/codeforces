#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 4000006;

int n;
string a[N];

int z;
int b[M][2];
bool c[M];

void clr(int pos)
{
    b[pos][0] = b[pos][1] = 0;
    c[pos] = false;
}

vector<int> v[2][2];
int q[2][2];

vector<int> ans;

void solv()
{
    z = 0;
    clr(z);
    memset(q, 0, sizeof q);
    v[0][1].clear();
    v[1][0].clear();
    ans.clear();
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        int m = a[i].size();
        int pos = 0;
        for (int j = 0; j < m; ++j)
        {
            if (!b[pos][a[i][j] - '0'])
            {
                b[pos][a[i][j] - '0'] = ++z;
                clr(z);
            }
            pos = b[pos][a[i][j] - '0'];
        }
        c[pos] = true;
    }
    for (int i = 0; i < n; ++i)
    {
        int m = a[i].size();
        if (a[i][0] == a[i][m - 1])
        {
            if (a[i][0] == '1')
                q[1][1]++;
            else
                q[0][0]++;
            continue;
        }
        bool z = true;
        int pos = 0;
        for (int j = m - 1; j >= 0; --j)
        {
            if (!b[pos][a[i][j] - '0'])
            {
                z = false;
                break;
            }
            pos = b[pos][a[i][j] - '0'];
        }
        if (z)
            z = c[pos];
        if (z)
        {
            q[a[i][0] - '0'][a[i][m - 1] - '0']++;
        }
        else
        {
            v[a[i][0] - '0'][a[i][m - 1] - '0'].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i)
        a[i].clear();
    if (q[1][0] == 0 && q[0][1] == 0 && v[0][1].empty() && v[1][0].empty())
    {
        if (q[0][0] && q[1][1])
        {
            printf("-1\n");
            return;
        }
        printf("0\n");
        printf("\n");
        return;
    }
    while (abs(q[0][1] + (int)v[0][1].size() - q[1][0] - (int)v[1][0].size()) > 1)
    {
        if (v[0][1].size() > v[1][0].size())
        {
            ans.push_back(v[0][1].back());
            v[1][0].push_back(v[0][1].back());
            v[0][1].pop_back();
        }
        else
        {
            ans.push_back(v[1][0].back());
            v[0][1].push_back(v[1][0].back());
            v[1][0].pop_back();
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i] + 1);
    printf("\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}