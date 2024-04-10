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
#define div fashion_is_my_profession

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int M = 1e9 + 7;

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

inline int div(int a, int b)
{
    return mul(a, bin(b, M - 2));
}

inline int det(vector <vector <int> > a)
{
    int n = a.size();
    int ptr = 0;
    int ans = 1;
    for (int it = 0; it < n; it++)
    {
        int x = -1;
        for (int i = ptr; i < n; i++)
        {
            if (a[i][it])
            {
                x = i;
            }
        }
        if (x == -1)
        {
            continue;
        }
        else
        {
            if (x != ptr)
            {
                swap(a[ptr], a[x]);
                ans = mul(ans, M - 1);
            }
            for (int i = ptr + 1; i < n; i++)
            {
                int v = div(a[i][it], a[ptr][it]);
                for (int j = 0; j < n; j++)
                {
                    a[i][j] = add(a[i][j], -mul(v, a[ptr][j]));
                }
            }
            ptr++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans = mul(ans, a[i][i]);
    }
    return ans;
}

vector <int> add(const vector <int> &a, const vector <int> &b)
{
    if (a.size() > b.size())
    {
        vector <int> ret = a;
        for (int i = 0; i < (int) b.size(); i++)
        {
            ret[i] = add(ret[i], b[i]);
        }
        return ret;
    }
    else
    {
        vector <int> ret = b;
        for (int i = 0; i < (int) a.size(); i++)
        {
            ret[i] = add(ret[i], a[i]);
        }
        return ret;
    }
}

vector <int> mul_x(vector <int> a)
{
    a.insert(a.begin(), 0); 
    return a;
}

vector <int> interpolate(vector <int> x, vector <int> val)
{
    int n = (int) x.size();
    vector <int> cur;
    for (int i = 0; i < n; i++)
    {
        vector <int> kek = {1};
        int ok = 1;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                vector <int> l = mul_x(kek);
                vector <int> r = kek;
                for (int &y : r) y = mul(y, M - x[j]);
                kek = add(l, r);
                ok = mul(ok, add(x[i], M - x[j]));
            }
        }
        for (int &y : kek) y = mul(y, div(val[i], ok));
        cur = add(cur, kek);
    }
    return cur;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    cin >> n;
    vector <vector <int> > w(n, vector <int> (n));
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        w[a][b] = w[b][a] = 1;
    }
    vector <int> val_x, val;
    for (int x = 0; x < n; x++)
    {
        vector <vector <int> > a(n);
        for (int i = 0; i < n; i++)
        {
            a[i].resize(n);
        }
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (w[i][j])
                {
                    sum = add(sum, x);
                }
                else if (i != j)
                {
                    sum = add(sum, 1);
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    a[i][j] = sum;
                }
                else if (w[i][j])
                {
                    a[i][j] = add(0, -x);
                }
                else
                {
                    a[i][j] = add(0, -1);
                }
            }
        }
        vector <vector <int> > b(n - 1, vector <int> (n - 1));
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                b[i][j] = a[i][j];
            }
        }
        int ret = det(b);
        val_x.push_back(x);
        val.push_back(ret);
    }
    vector <int> ret = interpolate(val_x, val);
    for (int i = 0; i <= n - 1; i++)
    {
        cout << ret[i] << ' ';
    }
    cout << '\n';
}