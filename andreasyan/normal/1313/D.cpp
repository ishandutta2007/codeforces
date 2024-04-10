#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005, K = 8;
struct ban
{
    int x, z;
    ban(){}
    ban(int x, int z)
    {
        this->x = x;
        this->z = z;
    }
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.z < b.z;
}

int n, m, k;
vector<ban> v;

int b[N];
bool c[K];

int dp[(1 << K)], ndp[(1 << K)];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        v.push_back(ban(l, i));
        v.push_back(ban(r + 1, -i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        memset(ndp, 0, sizeof ndp);
        int z = v[i].z;
        if (z > 0)
        {
            int j;
            for (int i = 0; i < k; ++i)
            {
                if (!c[i])
                {
                    b[z] = i;
                    j = i;
                    break;
                }
            }
            for (int x = 0; x < (1 << k); ++x)
            {
                bool z = true;
                int q = 0;
                for (int i = 0; i < k; ++i)
                {
                    if ((x & (1 << i)))
                    {
                        ++q;
                        if (!c[i])
                        {
                            z = false;
                            break;
                        }
                    }
                }
                if (!z)
                    continue;
                if (q % 2 == 0)
                    ndp[x] = max(ndp[x], dp[x]);
                else
                    ndp[x] = max(ndp[x], dp[x] + v[i + 1].x - v[i].x);
                if ((q + 1) % 2 == 0)
                    ndp[(x ^ (1 << j))] = max(ndp[(x ^ (1 << j))], dp[x]);
                else
                    ndp[(x ^ (1 << j))] = max(ndp[(x ^ (1 << j))], dp[x] + v[i + 1].x - v[i].x);
            }
            c[j] = true;
        }
        else
        {
            int j = b[-z];
            for (int x = 0; x < (1 << k); ++x)
            {
                bool z = true;
                int q = 0;
                for (int i = 0; i < k; ++i)
                {
                    if ((x & (1 << i)))
                    {
                        ++q;
                        if (!c[i])
                        {
                            z = false;
                            break;
                        }
                    }
                }
                if (!z)
                    continue;
                if (!(x & (1 << j)))
                {
                    if (q % 2 == 0)
                        ndp[x] = max(ndp[x], dp[x]);
                    else
                        ndp[x] = max(ndp[x], dp[x] + v[i + 1].x - v[i].x);
                }
                else
                {
                    if ((q - 1) % 2 == 0)
                        ndp[(x ^ (1 << j))] = max(ndp[(x ^ (1 << j))], dp[x]);
                    else
                        ndp[(x ^ (1 << j))] = max(ndp[(x ^ (1 << j))], dp[x] + v[i + 1].x - v[i].x);
                }
            }
            c[j] = false;
        }
        memcpy(dp, ndp, sizeof ndp);
    }
    printf("%d\n", dp[0]);
    return 0;
}