#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define int long long
const int N = 1000006;

int n;
long long k;
vector<pair<int, long long> > a[N];

long long v[N];
void dfs(int x, long long d)
{
    v[x] = d;
    for (int i = 0; i < a[x].size(); ++i)
    {
        dfs(a[x][i].first, a[x][i].second ^ d);
    }
}

int z = 1;
int t[N][2];
int q[N];

long long ans;

int pos[N];
int pos1[N];

int32_t main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 2; i <= n; ++i)
    {
        int p;
        long long w;
        cin >> p >> w;
        a[p].push_back(m_p(i, w));
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        pos[i] = 1;
        pos1[i] = 1;
    }
    for (int j = 61; j >= 0; --j)
    {
        for (int i = 1; i <= z; ++i)
            t[i][0] = t[i][1] = q[i] = 0;
        z = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (!t[pos1[i]][!!(v[i] & (1LL << j))])
            {
                    t[pos1[i]][!!(v[i] & (1LL << j))] = z++;
            }
            pos1[i] = t[pos1[i]][!!(v[i] & (1LL << j))];
            q[pos1[i]]++;
        }
        long long kk = 0;
        for (int i = 1; i <= n; ++i)
        {
            kk += (q[t[pos[i]][0 ^ !!((1LL << j) & v[i])]]);
        }
        if (k <= kk)
        {
            for (int i = 1; i <= n; ++i)
            {
                pos[i] = t[pos[i]][0 ^ !!((1LL << j) & v[i])];
            }
        }
        else
        {
            ans |= (1LL << j);
            k -= kk;
            for (int i = 1; i <= n; ++i)
            {
                pos[i] = t[pos[i]][1 ^ !!((1LL << j) & v[i])];
            }
        }
    }
    cout << ans << endl;
    return 0;
}