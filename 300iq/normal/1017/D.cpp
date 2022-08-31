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

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int q, m;
    cin >> n >> m >> q;
    vector <int> w(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        sum += w[i];
        w[i] *= -1;
    }
    int lim = (1 << n);
    vector <int> dp(lim);
    dp[0] = 0;
    for (int i = 1; i < lim; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                dp[i] = dp[i - (1 << j)] + w[j];
                break;
            }
        }
    }
    vector <int> cnt(lim);
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        int x = 0;
        for (auto c : s)
        {
            x = x * 2 + c - '0';
        }
        cnt[x]++;
    }
    vector <pair <int, pair <int, int> > > e;
    for (int i = 0; i < lim; i++)
    {
        e.push_back({dp[i], {-1, i}});
    }
    for (int i = 0; i < q; i++)
    {
        string t;
        cin >> t;
        reverse(t.begin(), t.end());
        int x = 0;
        for (auto c : t)
        {
            x = x * 2 + c - '0';
        }
        int k;
        cin >> k;
        k -= sum;
        e.push_back({k, {i, x}});
    }
    sort(e.begin(), e.end());
    vector <int> ans(lim);
    vector <int> ret(q);
    for (auto c : e)
    {
        if (c.second.first == -1)
        {
            int mask = c.second.second;
            for (int cur = 0; cur < lim; cur++)
            {
                ans[cur ^ mask] += cnt[cur];
            }
        }
        else
        {
            ret[c.second.first] = ans[c.second.second];
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << ret[i] << '\n';
    }
}