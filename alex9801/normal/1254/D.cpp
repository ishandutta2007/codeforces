#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int ipow(int x, int y)
{
    if(y == 0)
        return 1;
    if(y % 2 == 1)
        return 1LL * x * ipow(x, y - 1) % mod;
    int t = ipow(x, y / 2);
    return 1LL * t * t % mod;
}
int rev(int x)
{
    return ipow(x, mod - 2);
}

vector<int> arr[150010];
vector<pair<int, vector<int>>> chi[150010];
int cnt[150010];

int ren[150010];

void f(int x, int p)
{
    cnt[x] = 1;

    vector<pair<int, int>> v;
    for(int y : arr[x])
    {
        if(y == p)
            continue;

        f(y, x);
        cnt[x] += cnt[y];
        v.push_back({ cnt[y], y });
    }
    sort(v.begin(), v.end());

    int sz = (int)v.size();
    for(int i = 0; i < sz; i++)
    {
        if(i == 0 || v[i - 1].first != v[i].first)
            chi[x].push_back({ v[i].first, vector<int>() });

        chi[x].back().second.push_back(v[i].second);
    }
}

int cur = 1;
void g(int x)
{
    ren[x] = cur;
    cur++;

    for(auto& p : chi[x])
        for(int y : p.second)
            g(y);
}

long long idx[525000];
int bp;
void add(int x, int y, long long v)
{
    if(y < x)
        return;

    x += bp;
    y += bp;
    while(x <= y)
    {
        if(x % 2 == 1)
        {
            idx[x++] += v;
        }
        if(y % 2 == 0)
        {
            idx[y--] += v;
        }
        x /= 2;
        y /= 2;
    }
}
long long val(int x)
{
    x += bp;
    long long r = 0;
    while(x)
    {
        r += idx[x];
        x /= 2;
    }
    return r;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    for(bp = 1; bp < n + 1; bp *= 2);

    f(1, -1);
    g(1);

    long long tot = 0;
    long long tot2 = 0;
    int rn = rev(n);
    for(int i = 0; i < q; i++)
    {
        int t, v;
        scanf("%d%d", &t, &v);
        if(t == 1)
        {
            int d;
            scanf("%d", &d);

            long long tmp = 1LL * d * (n - cnt[v]);
            add(ren[v], ren[v], tmp);

            tot += d;
            tot2 += -tmp;

            int c = ren[v] + 1;
            for(auto& p : chi[v])
            {
                int sz = p.first;
                int len = (int)p.second.size();

                add(c, c + sz * len - 1, tmp - 1LL * d * sz);
                c += sz * len;
            }
        }
        else
        {
            int res = (((val(ren[v]) + tot2) % mod * rn + tot) % mod + mod) % mod;
            printf("%d\n", res);
        }
    }
    return 0;
}