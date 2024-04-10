#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 300005;

int n, m;
vector<int> v[4];

void solv()
{
    scanf("%d%d", &n, &m);
    while (n--)
    {
        int u, x;
        scanf("%d%d", &u, &x);
        v[u].push_back(x);
    }
    for (int i = 1; i <= 3; ++i)
    {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
    }
    long long ans = 0;
    for (int q3 = 0; q3 < 2; ++q3)
    {
        if (q3 > v[3].size())
            continue;
        for (int q2 = 0; q2 < 3; ++q2)
        {
            if (q2 > v[2].size())
                continue;
            for (int q1 = 0; q1 < 6; ++q1)
            {
                if (q1 > v[1].size())
                    continue;
                if (m - q3 * 3 - q2 * 2 - q1 < 0)
                    continue;
                long long yans = 0;
                for (int i = 0; i < q3; ++i)
                    yans += v[3][i];
                for (int i = 0; i < q2; ++i)
                    yans += v[2][i];
                for (int i = 0; i < q1; ++i)
                    yans += v[1][i];
                vector<long long> vv;
                for (int i = q3; i + 1 < v[3].size(); i += 2)
                {
                    long long s = 0;
                    for (int j = i; j <= i + 1; ++j)
                        s += v[3][j];
                    vv.push_back(s);
                }
                for (int i = q2; i + 2 < v[2].size(); i += 3)
                {
                    long long s = 0;
                    for (int j = i; j <= i + 2; ++j)
                        s += v[2][j];
                    vv.push_back(s);
                }
                for (int i = q1; i + 5 < v[1].size(); i += 6)
                {
                    long long s = 0;
                    for (int j = i; j <= i + 5; ++j)
                        s += v[1][j];
                    vv.push_back(s);
                }
                sort(vv.begin(), vv.end());
                reverse(vv.begin(), vv.end());
                for (int i = 0; i < min((m - q3 * 3 - q2 * 2 - q1) / 6, (int)vv.size()); ++i)
                    yans += vv[i];
                ans = max(ans, yans);
            }
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}