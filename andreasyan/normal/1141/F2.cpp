#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1503;

int n;
int a[N];
int pp[N];

int dp[N][N];
int dpp[N][N];

map<int, vector<pair<int, int> > > v;
map<int, vector<int> > p;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        pp[i] = pp[i - 1] + a[i];
    for (int r = 1; r <= n; ++r)
    {
        int s = 0;
        for (int l = r; l >= 1; --l)
        {
            s += a[l];
            v[s].push_back(m_p(l, r));
        }
    }
    for (map<int, vector<pair<int, int> > >::iterator it = v.begin(); it != v.end(); ++it)
    {
        p[it->first].assign(it->second.size(), 0);
        int maxu = it->second[0].first;
        p[it->first][0] = 0;
        for (int i = 1; i < it->second.size(); ++i)
        {
            if (it->second[i].first < maxu)
                p[it->first][i] = p[it->first][i - 1];
            else
            {
                p[it->first][i] = i;
                maxu = it->second[i].first;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int s = 0;
        for (int j = i; j >= 1; --j)
        {
            s += a[j];
            int l = 0, r = v[s].size() - 1;
            int ans = -1;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (v[s][m].second < j)
                {
                    ans = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            dpp[j][i] = ans;
            if (ans == -1)
                dp[j][i] = 1;
            else
                dp[j][i] = dp[v[s][p[s][ans]].first][v[s][p[s][ans]].second] + 1;
        }
    }
    int yans = 0;
    for (int l = 1; l <= n; ++l)
    {
        for (int r = l; r <= n; ++r)
            yans = max(yans, dp[l][r]);
    }
    printf("%d\n", yans);
    for (int l = 1; l <= n; ++l)
    {
        for (int r = l; r <= n; ++r)
        {
            if (dp[l][r] == yans)
            {
                vector<pair<int, int> > ans;
                while (1)
                {
                    ans.push_back(m_p(l, r));
                    if (dpp[l][r] == -1)
                        break;
                    int s = pp[r] - pp[l - 1];
                    int u = dpp[l][r];
                    l = v[s][p[s][u]].first;
                    r = v[s][p[s][u]].second;
                }
                reverse(ans.begin(), ans.end());
                for (int i = 0; i < yans; ++i)
                    printf("%d %d\n", ans[i].first, ans[i].second);
                return 0;
            }
        }
    }
    return 0;
}