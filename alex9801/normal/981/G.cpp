#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <iterator>

using namespace std;

struct str
{
    int x, a, b;
    // * 2^a + b
};

set<pair<int, int>> arr[200010];
str mem[525000];
int ipow[525000];
int n, q;
const int mod = 998244353;

void prop(int x, int s, int g)
{
    int a = mem[x].a;
    int b = mem[x].b;
    mem[x].a = mem[x].b = 0;

    for(int i = 2 * x; i <= 2 * x + 1; i++)
    {
        int len = (g - s + 1 + (i == 2 * x ? 1 : 0)) / 2;
        mem[i].x = (1LL * mem[i].x * ipow[a] + 1LL * b * len) % mod;
        mem[i].a += a;
        mem[i].b = (1LL * ipow[a] * mem[i].b + b) % mod;
    }
}

void upd(int x, int s, int g, int l, int r, bool v)
{
    if(r < l || r < s || g < l)
        return;

    if(l <= s && g <= r)
    {
        if(v)
        {
            mem[x].x = mem[x].x * 2 % mod;
            mem[x].a++;
            mem[x].b = mem[x].b * 2 % mod;
        }
        else
        {
            mem[x].x = (mem[x].x + (g - s + 1)) % mod;
            mem[x].b = (mem[x].b + 1) % mod;
        }
    }
    else
    {
        prop(x, s, g);
        upd(2 * x, s, (s + g) / 2, l, r, v);
        upd(2 * x + 1, (s + g) / 2 + 1, g, l, r, v);
        mem[x].x = (mem[2 * x].x + mem[2 * x + 1].x) % mod;
    }
}

int sum(int x, int s, int g, int l, int r)
{
    if(r < l || r < s || g < l)
        return 0;

    if(l <= s && g <= r)
        return mem[x].x;
    else
    {
        prop(x, s, g);
        int res = (sum(2 * x, s, (s + g) / 2, l, r) +
            sum(2 * x + 1, (s + g) / 2 + 1, g, l, r)) % mod;
        mem[x].x = (mem[2 * x].x + mem[2 * x + 1].x) % mod;
        return res;
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int i;
    scanf("%d%d", &n, &q);

    ipow[0] = 1;
    for(i = 1; i <= q; i++)
        ipow[i] = ipow[i - 1] * 2 % mod;

    for(i = 0; i < q; i++)
    {
        int t, l, r, x;
        scanf("%d%d%d", &t, &l, &r);
        if(t == 1)
        {
            scanf("%d", &x);

            auto it = arr[x].lower_bound({ l, -1 });
            auto it2 = it;

            int s = l;
            if(it != arr[x].begin() && prev(it)->second >= l - 1)
            {
                if(r <= prev(it)->second)
                {
                    upd(1, 1, n, l, r, 1);
                    continue;
                }

                upd(1, 1, n, l, prev(it)->second, 1);
                s = prev(it)->second + 1;
                it2 = prev(it);
            }

            while(it != arr[x].end() && it->first <= r + 1)
            {
                upd(1, 1, n, s, it->first - 1, 0);
                upd(1, 1, n, it->first, min(it->second, r), 1);

                s = min(it->second, r) + 1;
                it++;
            }
            upd(1, 1, n, s, r, 0);

            int nl = l, nr = r;
            while(it2 != arr[x].end() && it2->first <= r + 1)
            {
                nl = min(nl, it2->first);
                nr = max(nr, it2->second);

                it2++;
                arr[x].erase(prev(it2));
            }

            arr[x].insert({ nl, nr });
        }
        else
            printf("%d\n", sum(1, 1, n, l, r));
    }
    return 0;
}