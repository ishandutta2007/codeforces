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

const int N = 1e5 + 7;

int t[N];
ll _f[N];

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

void _inc(int x, ll y)
{
    for (; x < N; x = (x | (x + 1)))
    {
        _f[x] += y;
    }
}

ll _get(int x)
{
    ll ans = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
    {
        ans += _f[x];
    }
    return ans;
}

ll f(ll sum, const vector <int> &a)
{
    for (int i = 0; i < N; i++) t[i] = 0;
    vector <ll> ret = {0};
    ll s = 0;
    for (int x : a)
    {
        s += x;
        ret.push_back(s);
    }
    vector <ll> p;
    for (int i = 0; i < (int) ret.size(); i++)
    {
        p.push_back(ret[i]);
    }
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    ll ans = 0;
    for (int i = 0; i < (int) ret.size(); i++)
    {
        int _ret = upper_bound(p.begin(), p.end(), ret[i] - sum) - p.begin();
        _ret--;
        ans += get(_ret);
        inc(lower_bound(p.begin(), p.end(), ret[i]) - p.begin());
    }
    return ans;
}

ll _sum(ll sum, const vector <int> &a)
{
    for (int i = 0; i < N; i++) t[i] = 0, _f[i] = 0;
    vector <ll> ret = {0};
    ll s = 0;
    for (int x : a)
    {
        s += x;
        ret.push_back(s);
    }
    vector <ll> p;
    for (int i = 0; i < (int) ret.size(); i++)
    {
        p.push_back(ret[i]);
    }
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    ll ans = 0;
    for (int i = 0; i < (int) ret.size(); i++)
    {
        int _ret = upper_bound(p.begin(), p.end(), ret[i] - sum) - p.begin();
        _ret--;
        ans += get(_ret) * ret[i] - _get(_ret);
        inc(lower_bound(p.begin(), p.end(), ret[i]) - p.begin());
        _inc(lower_bound(p.begin(), p.end(), ret[i]) - p.begin(), ret[i]);
    }
    return ans;
}

vector <pair <int, int> > get_all(ll l, ll r, const vector <int> &a)
{
    vector <ll> ret = {0};
    ll s = 0;
    for (int x : a)
    {
        s += x;
        ret.push_back(s);
    }
    set <pair <ll, int> > q;
    vector <pair <int, int> > segs;
    for (int i = 0; i < (int) ret.size(); i++)
    {
        auto it = q.lower_bound({ret[i] - r, -1});
        while (it != q.end() && it->first <= ret[i] - l)
        {
            segs.push_back({it->second, i - 1});
            it++;
        }
        q.insert({ret[i], i});
    }
    return segs;
}

vector <pair <int, int> > get_cnt(ll x, int x1, int x2, const vector <int> &a)
{
    vector <ll> ret = {0};
    ll s = 0;
    for (int x : a)
    {
        s += x;
        ret.push_back(s);
    }
    map <ll, vector <int> > dp;
    vector <pair <int, int> > segs;
    vector <int> ptr(ret.size());
    for (int i = 0; i < (int) ret.size(); i++)
    {
        for (int it = 0; it < (int) dp[ret[i] - x].size(); it++)
        {
            if (!x1)
            {
                break;
            }
            segs.push_back({dp[ret[i] - x][it], i - 1});
            x1--;
            ptr[i] = it + 1;
            break;
        }
        dp[ret[i]].push_back(i);
    }
    for (auto &c : dp) c.second.clear();
    for (int i = 0; i < (int) ret.size(); i++)
    {
        for (int it = ptr[i]; it < (int) dp[ret[i] - x].size(); it++)
        {
            if (!x2)
            {
                break;
            }
            segs.push_back({dp[ret[i] - x][it], i - 1});
            x2--;
        }
        dp[ret[i]].push_back(i);
    }
    return segs;
}

vector <pair <int, int> > up(ll sum, const vector <int> &a)
{
    vector <ll> ret = {0};
    ll s = 0;
    for (int x : a)
    {
        s += x;
        ret.push_back(s);
    }
    set <pair <ll, int> > q;
    vector <pair <int, int> > segs;
    for (int i = 0; i < (int) ret.size(); i++)
    {
        auto it = q.upper_bound({ret[i] - sum, N});
        if (it != q.begin())
        {
            it--;
            segs.push_back({it->second, i - 1});
        }
        it = q.lower_bound({ret[i], i});
        if (it != q.begin() && prev(it)->second < i)
        {
            continue;
        }
        while (true)
        {
            auto it = q.lower_bound({ret[i], i});
            if (it != q.end() && it->second >= i)
            {
                q.erase(it);
            }
            else
            {
                break;
            }
        }
        q.insert({ret[i], i});
    }
    return segs;
}

struct value
{
    ll pref, suf, mx, sum;
};

value operator + (const value &a, const value &b)
{
    value ret;
    ret.pref = max(a.pref, a.sum + b.pref);
    ret.suf = max(b.suf, b.sum + a.suf);
    ret.mx = max(max(a.mx, b.mx), a.suf + b.pref);
    ret.sum = a.sum + b.sum;
    return ret;
}

value tree[4 * N];

void upd(int v, int l, int r, int i, ll x)
{
    if (r - l == 1)
    {
        if (x < 0)
        {
            tree[v] = {0, 0, 0, x};
        }
        else
        {
            tree[v] = {x, x, x, x};
        }
    }
    else
    {
        int m = (l + r) / 2;
        if (i < m)
        {
            upd(v * 2 + 1, l, m, i, x);
        }
        else
        {
            upd(v * 2 + 2, m, r, i, x);
        }
        tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
    }
}

value get(int v, int l, int r, int tl, int tr)
{
    if (tl >= r || tr <= l)
    {
        return {0, 0, 0, 0};
    }
    if (tl >= l && tr <= r)
    {
        return tree[v];
    }
    else
    {
        int tm = (tl + tr) / 2;
        return get(v * 2 + 1, l, r, tl, tm) + get(v * 2 + 2, l, r, tm, tr);
    }
}

ll smart(int n, ll k, vector <int> a)
{
    ll need = max(0ll, k - n);
    ll l = -1e10, r = 1e10;
    while (l < r - 1)
    {
        ll m = (l + r) / 2;
        if (f(m, a) >= need)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    ll ans = 0;
    ll more = min(k, (ll) n);
    ll need_l = need - f(l + 1, a);
    auto x1 = up(l + 1, a);
    ans += _sum(l + 1, a);
    ans += l * need_l;
    ll cnt = f(l, a) - f(l + 1, a);
    cnt -= need_l;
    cnt = min(cnt, more);
    auto x2 = get_cnt(l, need_l, cnt, a);
    vector <pair <int, int> > x3;
    for (int it = 0; it < cnt; it++)
    {
        x3.push_back(x2.back());
        x2.pop_back();
    }
    ll sum = cnt + need;
    ll vl = -1e10, vr = 1e10;
    while (vl < vr - 1)
    {
        ll vm = (vl + vr) / 2;
        if (f(vm, a) >= k)
        {
            vl = vm;
        }
        else
        {
            vr = vm;
        }
    }
    for (auto c : x2) x1.push_back(c);
    auto x4 = get_all(vl + 1, l - 1, a);
    sum += x4.size();
    auto x5 = get_cnt(vl, 0, k - sum, a);
    for (auto c : x4) x3.push_back(c);
    for (auto c : x5) x3.push_back(c);
    auto grab = x1;
    auto add = x3;
    vector <ll> pref(n + 1);
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + a[i];
    }
    auto get_sum = [&] (int l, int r)
    {
        if (l > r) return 0ll;
        return pref[r + 1] - pref[l];
    };
    sort(add.begin(), add.end(), [&] (pair <int, int> a, pair <int, int> b)
    {
        return get_sum(a.first, a.second) > get_sum(b.first, b.second);
    });
    vector <int> bal(n + 1);
    for (auto c : grab)
    {
        bal[c.first]++;
        bal[c.second + 1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        bal[i] += bal[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        upd(0, 0, n, i, a[i]);
    }
    set <int> q;
    multiset <ll> in_q, out_q;
    ll cur_value = ans;
    ans = LLONG_MIN;
    auto cost = [&] (int l, int r)
    {
        ll ultra_value = 0;
        if (l <= r)
        {
            auto ret = get(0, l, r + 1, 0, n);
            ultra_value = ret.pref + ret.suf - ret.sum;
        }
        return ultra_value;
    };
    auto buf = [&] (int l, int r)
    {
        ll ultra_value = cost(l, r);
        if (in_q.find(ultra_value) != in_q.end())
        {
            cur_value -= ultra_value;
            in_q.erase(in_q.find(ultra_value));
        }
        else
        {
            out_q.erase(out_q.find(ultra_value));
        }
    };
    auto del = [&] (int x)
    {
        auto it = q.find(x);
        if (it != q.begin())
        {
            int l = *prev(it) + 1;
            int r = *it - 1;
            buf(l, r);
        }
        if (next(it) != q.end())
        {
            int l = *it + 1;
            int r = *next(it) - 1;
            buf(l, r);
        }
        if (it != q.begin() && next(it) != q.end())
        {
            int l = *prev(it) + 1;
            int r = *next(it) - 1;
            out_q.insert(cost(l, r));
        }
    };
    for (int i = 0; i < n; i++)
    {
        q.insert(i);
        if (i)
        {
            out_q.insert(0);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (bal[i])
        {
            del(i);
            q.erase(i);
        }
    }
    for (int x = 0; x <= more; x++)
    {
        if ((int) q.size() - 1 >= more - 1 - x)
        {
            if (x == more)
            {
                if (q.size() == 0)
                    ans = max(ans, cur_value);
                continue;
            }
            while (in_q.size() < more - 1 - x)
            {
                cur_value += *out_q.rbegin();
                in_q.insert(*out_q.rbegin());
                out_q.erase(--out_q.end());
            }
            while (in_q.size() > more - 1 - x)
            {
                cur_value -= *in_q.begin();
                out_q.insert(*in_q.begin());
                in_q.erase(in_q.begin());
            }
            while (!in_q.empty() && !out_q.empty() && *in_q.begin() < *out_q.rbegin())
            {
                ll x = *in_q.begin();
                ll y = *out_q.rbegin();
                cur_value -= x;
                cur_value += y;
                in_q.erase(in_q.find(x));
                out_q.erase(out_q.find(y));
                in_q.insert(y);
                out_q.insert(x);
            }
            ll sum = 0;
            if (!q.empty())
            {
                sum = get_sum(*q.begin(), *q.rbegin()) + get(0, 0, *q.begin(), 0, n).suf + get(0, *q.rbegin() + 1, n, 0, n).pref;
            }
            sum += cur_value;
            ans = max(ans, sum);
        }
        if (x != more)
        {
            while (true)
            {
                auto it = q.lower_bound(add[x].first);
                if (it != q.end() && *it <= add[x].second)
                {
                    del(*it);
                    q.erase(it);
                }
                else
                {
                    break;
                }
            }
            cur_value += get_sum(add[x].first, add[x].second);
        }
    }
    return ans;
}

int stup(int n, ll k, vector <int> a)
{
    vector <pair <int, int> > e;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            e.push_back({i, j});
        }
    }
    int m = (int) e.size();
    int lim = (1 << m);
    int ans = -1e9;
    for (int mask = 0; mask < lim; mask++)
    {
        if (__builtin_popcount(mask) == k)
        {
            vector <int> cnt(n);
            for (int i = 0; i < m; i++)
            {
                if ((mask >> i) & 1)
                {
                    for (int x = e[i].first; x <= e[i].second; x++) cnt[x]++;
                }
            }
            bool bad = false;
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (!cnt[i]) bad = true;
                sum += cnt[i] * a[i];
            }
            if (!bad)
            {
                ans = max(ans, sum);
            }
        }
    }
    return ans;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef ONPC
    int n = 1e5;
    ll k = n * (ll) (n + 1) / 2;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    cout << smart(n, k, a) << '\n';
    /*
    int cnt = 0;
    while (true)
    {
        int n = 1 + rnd() % 5;
        int k = rnd() % ((n * (n + 1)) / 2) + 1;
        vector <int> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = rnd() % 1000 - 500;
        }
        if (smart(n, k, a) != stup(n, k, a))
        {
            cout << n << ' ' << k << '\n';
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << ' ';
            }
            cout << '\n';
            return 0;
        }
        else
        {
            cnt++;
            cout << "OK" << ' ' << cnt << endl;
        }
    }
    */
#else
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << smart(n, k, a) << '\n';
#endif
}