#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;

const int N = 2e5 + 7;

vector <int> g[N];

void add(int u, int v)
{
    g[u].push_back(v);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    n -= k;
    int l = 0, r = n + k + 1;
    while (l < r - 1)
    {
        int m = (l + r) / 2;
        int len = m;
        if (len % 2 == 0)
        {
            int leafs = k;
            int cur = n;
            leafs -= 2;
            cur -= (len / 2 - 1) * 2;
            cur--;
            if (cur < 0)
            {
                r = m;
                continue;
            }
            ll may_add = leafs * (ll) ((len / 2 - 1));
            if (may_add >= cur)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        else
        {
            int leafs = k;
            int cur = n;
            leafs -= 2;
            cur -= ((len - 1) / 2) * 2;
            if (cur < 0)
            {
                r = m;
                continue;
            }
            int kek = max(0, (len - 1) / 2 - 1);
            ll may_add = leafs * (ll) kek;
            if (may_add >= cur)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
    }
    cout << r << '\n';
    int len = r;
    if (len % 2 == 0)
    {
        int leafs = k;
        int cur = n;
        int sz = 1;
        int cent_id = 0;
        for (int i = 0; i < len; i++)
        {
            add(sz, sz + 1);
            if (i == len / 2 - 1)
            {
                cent_id = sz + 1;
            }
            sz++;
        }
        cur -= (len / 2 - 1) * 2;
        cur--;
        leafs -= 2;
        for (int i = 0; i < leafs; i++)
        {
            int cnt = min(cur, ((len / 2 - 1)));
            add(cent_id, sz + 1);
            sz++;
            for (int j = 0; j < cnt; j++)
            {
                add(sz, sz + 1);
                sz++;
            }
            cur -= cnt;
        }
    }
    else
    {
        int leafs = k;
        int cur = n;
        leafs -= 2;
        cur -= ((len - 1) / 2) * 2;
        int cent_id = 0;
        int sz = 1;
        for (int i = 0; i < len; i++)
        {
            add(sz, sz + 1);
            if (i == len / 2)
            {
                cent_id = sz + 1;
            }
            sz++;
        }
        for (int i = 0; i < leafs; i++)
        {
            int cnt = min(cur, max(0, ((len - 1) / 2 - 1)));
            add(cent_id, sz + 1);
            sz++;
            for (int j = 0; j < cnt; j++)
            {
                add(sz, sz + 1);
                sz++;
            }
            cur -= cnt;
        }
    }
    for (int i = 1; i <= n + k; i++)
    {
        for (int to : g[i])
        {
            cout << i << ' ' << to << '\n';
        }
    }
}