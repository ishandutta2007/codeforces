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

const int M = 1e9 + 7;

inline int add(int a, int b)
{
    a += b;
    if (a >= M) a -= M;
    if (a < 0) a += M;
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

typedef vector <vector <int> > mat;

mat operator * (const mat &a, const mat &b)
{
    int n = (int) a.size();
    mat c(n, vector <int> (n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return c;
}

mat bin(mat a, ll x)
{
    int n = (int) a.size();
    mat res(n, vector <int> (n));
    for (int i = 0; i < n; i++)
    {
        res[i][i] = 1;
    }
    while (x)
    {
        if (x % 2 == 0)
        {
            a = a * a;
            x /= 2;
        }
        else
        {
            res = res * a;
            x--;
        }
    }
    return res;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    int k;
    cin >> n >> k;
    int sz = 2 * k + 3;
    vector <vector <int> > ret(sz, vector <int> (sz));
    vector <vector <int> > binom(k + 1, vector <int> (k + 1));
    vector <int> pw(k + 2);
    binom[0][0] = 1;
    pw[0] = 1;
    for (int i = 1; i <= k + 1; i++)
    {
        pw[i] = mul(pw[i - 1], 2);
    }
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i)
            {
                binom[i][j] = add(binom[i][j], binom[i - 1][j]);
            }
            if (i && j)
            {
                binom[i][j] = add(binom[i][j], binom[i - 1][j - 1]);
            }
        }
    }
    ret[k][k + k + 2] = 1;
    ret[k + k + 2][k + k + 2] = 1;
    for (int i = 0; i <= k; i++)
    {
        ret[k + 1 + i][i] = 1;
        for (int j = i; j <= k; j++)
        {
            ret[i][k + 1 + j] = mul(binom[j][i], pw[j - i]);
            ret[k + 1 + i][k + 1 + j] = binom[j][i];
        }
    }
    ret = bin(ret, n);
    int ans = 0;
    for (int i = 0; i <= k + k + 1; i++)
    {
        if (i <= k)
            ans = add(ans, ret[i][k + k + 2]);
        else
            ans = add(ans, mul(pw[i - k], ret[i][k + k + 2]));
    }
    cout << ans << '\n';
}