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
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

struct triple
{
    int a, b, c;
};

vector <bool> vis(1 << 14);
vector <vector <triple> > ans(1 << 14);
bool kekos = false;

vector <triple> zeros(int n, int mask)
{
    int lim = (1 << n);
    if (!kekos)
    {
        queue <int> q;
        for (int mask = 0; mask < lim; mask++)
        {
            bool bad = false;
            for (int i = (n - 6); i < n; i++)
            {
                if ((mask >> i) & 1) bad = true;
            }
            if (!bad)
            {
                vis[mask] = true;
                q.push(mask);
            }
        }
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    int k = j + j - i;
                    if (k < n)
                    {
                        int go = v;
                        go ^= (1 << i);
                        go ^= (1 << j);
                        go ^= (1 << k);
                        if (!vis[go])
                        {
                            vis[go] = true;
                            ans[go] = ans[v];
                            ans[go].push_back({i, j, k});
                            q.push(go);
                        }
                    }
                }
            }
        }
        kekos = true;
    }
    reverse(ans[mask].begin(), ans[mask].end());
    return ans[mask];
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        //a[i] = rnd() % 2;
        cin >> a[i];
    }
    vector <triple> ret;
    while ((int) a.size() - 6 >= 8)
    {
        if (!a.back())
        {
            n--;
            a.pop_back();
            continue;
        }
        int start = n - 14;
        int mask = 0;
        for (int i = start; i < n; i++)
        {
            if (a[i])
            {
                mask |= (1 << (i - start));
            }
        }
        auto get = zeros(14, mask);
        for (auto &c : get)
        {
            c.a += start, c.b += start, c.c += start;
            ret.push_back(c);
            a[c.a] ^= 1, a[c.b] ^= 1, a[c.c] ^= 1;
        }
    }
    int lim = (1 << n);
    queue <int> q;
    vector <bool> vis(lim);
    vector <vector <triple> > ans(lim);
    vis[0] = true;
    q.push(0);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int k = j + j - i;
                if (k < n)
                {
                    int go = v;
                    go ^= (1 << i);
                    go ^= (1 << j);
                    go ^= (1 << k);
                    if (!vis[go])
                    {
                        vis[go] = true;
                        ans[go] = ans[v];
                        ans[go].push_back({i, j, k});
                        q.push(go);
                    }
                }
            }
        }
    }
    int mask = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i])
        {
            mask |= (1 << i);
        }
    }
    if (!vis[mask])
    {
        cout << "NO\n";
        return 0;
    }
    else
    {
        cout << "YES\n";
        reverse(ans[mask].begin(), ans[mask].end());
        for (auto c : ans[mask]) ret.push_back(c);
        cout << ret.size() << '\n';
        for (auto c : ret)
        {
            cout << c.a + 1 << ' ' << c.b + 1 << ' ' << c.c + 1 << '\n';
        }
    }
}