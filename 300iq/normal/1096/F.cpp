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
#define div vid

using namespace std;

typedef long long ll;

#ifdef ONPC
    mt19937 rnd(228);
#else
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int M = 998244353;

inline int add(int a, int b)
{
    a += b;
    if (a < 0) a += M;
    if (a >= M) a -= M;
    return a;
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % M;
}

inline int bin(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            a = mul(a, a);
            n /= 2;
        }
        else
        {
            res = mul(res, a);
            n--;
        }
    }
    return res;
}

inline int inv(int x)
{
    return bin(x, M - 2);
}

inline int div(int a, int b)
{
    return mul(a, inv(b));
}

const int N = 2e5 + 7;

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

int invs(vector <int> a)
{
    for (int i = 0; i < N; i++)
    {
        t[i] = 0;
    }
    int ret = 0;
    reverse(a.begin(), a.end());
    for (int x : a)
    {
        inc(x);
        ret = add(ret, get(x - 1));
    }
    return ret;
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
    vector <int> p(n), array;
    set <int> q;
    for (int i = 1; i <= n; i++)
    {
        q.insert(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        q.erase(p[i]);
    }
    vector <int> pref(n + 1);
    for (int x : q)
    {
        pref[x]++;
    }
    for (int i = 1; i <= n; i++)
    {
        pref[i] += pref[i - 1];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i] == -1)
        {
            cnt++;
        }
        else
        {
            array.push_back(p[i]);
        }
    }
    int ans = div(cnt * (ll) (cnt - 1) / 2 % M, 2);
    int sum = 0;
    int bad_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i] == -1)
        {
            ans = add(ans, div(sum, cnt));
            bad_cnt++;
        }
        else
        {
            ans = add(ans, mul(bad_cnt, div(cnt - pref[p[i]], cnt)));
            sum = add(sum, pref[p[i] - 1]);
        }
    }
    cout << add(ans, invs(array)) << '\n';
}