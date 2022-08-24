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
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 5e6 + 7;
//const int K = 2e6 + 7;

bool prime[N];
int lp[N];
int t[N];

void inc(int x)
{
    for (; x < N; x = (x | (x + 1)))
    {
        t[x]++;
    }
}

int get(int x)
{
    int ans = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
    {
        ans += t[x];
    }
    return ans;
}

vector <ll> p;

struct hsh
{
    ll operator() (const pair <ll, int> &a) const
    {
        return a.first * 100000 + a.second;
    }
};

unordered_map <pair <ll, int>, ll, hsh> dp;

vector <pair <ll, int> > prec;

ll rec(ll n, int it)
{
    
    if (n < 2) return 0;
    it = min(it, (int) (upper_bound(p.begin(), p.end(), sqrt(n)) - p.begin()) - 1);
    if (it == -1)
    {
        return n - 1;
    }
    if (dp.count({n, it}))
    {
        return dp[{n, it}];
    }
    if (n < N)
    {
        dp[{n, it}] = -1;
        prec.push_back({n, it});
        return 0;
    }
    return dp[{n, it}] = rec(n, it - 1) - (rec(n / p[it], it - 1) - rec(p[it] - 1, it - 1));
}

ll pi(ll x)
{
    int it = lower_bound(p.begin(), p.end(), x) - p.begin();
    it = min(it, (int) (lower_bound(p.begin(), p.end(), sqrt(x)) - p.begin()));
    return rec(x, it);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    dp.reserve(1e8);
    dp.rehash(1e8);
    for (int i = 2; i < N; i++)
    {
        prime[i] = true;
        lp[i] = i;
    }
    for (int i = 2; i < N; i++)
    {
        if (prime[i])
        {
            for (int j = i + i; j < N; j += i)
            {
                prime[j] = false;
                lp[j] = min(lp[j], (int) p.size());
            }
            lp[i] = (int) p.size();
            p.push_back(i);
        }
    }
    ll n;
    cin >> n;
    {
        ll ans = 0;
        for (ll i = 2; i * i * i <= n; i++)
        {
            if (prime[i])
            {
                ans++;
            }
        }
        int cnt = 0;
        for (ll i = 2; i * i <= n; i++)
        {
            if (prime[i])
            {
                cnt++;
                ans += pi(n / i);
                ans -= cnt;
            }
        }
        dp.clear();
    }
    sort(prec.begin(), prec.end());
    int ptr = -1;
    for (int i = 2; i < N; i++)
    {
        if (!prime[i])
        {
            inc(lp[i]);
        }
        while (ptr + 1 < (int) prec.size() && prec[ptr + 1].first <= i)
        {
            ptr++;
            dp[prec[ptr]] = i - 1 - get(prec[ptr].second);
        }
    }
    {
        ll ans = 0;
        for (ll i = 2; i * i * i <= n; i++)
        {
            if (prime[i])
            {
                ans++;
            }
        }
        int cnt = 0;
        for (ll i = 2; i * i <= n; i++)
        {
            if (prime[i])
            {
                cnt++;
                ans += pi(n / i);
                ans -= cnt;
            }
        }
        cout << ans << '\n';
    }
}