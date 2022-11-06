#include<bits/stdc++.h>
using namespace std;

int seed;
int rnd()
{
    int ret = seed;
    seed = (seed * 7LL + 13) % 1000000007;
    return ret;
}

int ipow(int a, int x, int m)
{
    if(x == 1)
        return a % m;
    if(x % 2)
        return 1LL * ipow(a, x - 1, m) * a % m;
    int t = ipow(a, x / 2, m);
    return 1LL * t * t % m;
}

int main()
{
    int n, m, vmax;
    scanf("%d%d%d%d", &n, &m, &seed, &vmax);

    map<int, long long> mem;
    mem.insert({ n, -1 });

    int pre = -1;
    for(int i = 0; i < n; i++)
    {
        int t = rnd() % vmax + 1;
        if(t != pre)
        {
            mem.insert({ i, t });
            pre = t;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int op = rnd() % 4 + 1;
        int l = rnd() % n;
        int r = rnd() % n;
        if(l > r)
            swap(l, r);

        auto lit = prev(mem.upper_bound(l));
        if(lit->first != l)
        {
            bool ok;
            tie(lit, ok) = mem.insert({ l, lit->second });
            assert(ok);
        }

        auto rit = mem.upper_bound(r);
        if(rit->first != r + 1)
        {
            bool ok;
            tie(rit, ok) = mem.insert({ r + 1, prev(rit)->second });
            assert(ok);
        }

        assert(lit != rit);

        if(op == 1)
        {
            int x = rnd() % vmax + 1;

            while(lit != rit)
            {
                lit->second += x;
                lit++;
            }
        }
        else if(op == 2)
        {
            int x = rnd() % vmax + 1;

            lit->second = x;
            lit++;
            while(lit != rit)
                lit = mem.erase(lit);
        }
        else if(op == 3)
        {
            int x = rnd() % (r - l + 1) + 1;

            vector<pair<long long, int>> sor;
            while(lit != rit)
            {
                sor.push_back({ lit->second, min(r + 1, next(lit)->first) - max(l, lit->first) });
                lit++;
            }

            sort(sor.begin(), sor.end());
            int cnt = 0;
            for(auto& [v, c] : sor)
            {
                cnt += c;
                if(cnt >= x)
                {
                    printf("%lld\n", v);
                    break;
                }
            }
        }
        else if(op == 4)
        {
            int x = rnd() % vmax + 1;
            int y = rnd() % vmax + 1;

            long long res = 0;
            while(lit != rit)
            {
                res += 1LL * ipow(lit->second % y, x, y) * (min(r + 1, next(lit)->first) - max(l, lit->first));
                lit++;
            }

            res %= y;
            printf("%lld\n", res);
        }
    }
    return 0;
}