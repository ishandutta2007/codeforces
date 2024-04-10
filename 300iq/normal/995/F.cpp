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
#define div asddjklaasdfhjkoasdfhjkl

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

int ans(vector <int> x, vector <int> val, int ret)
{
    int n = (int) x.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int ds = 1;
        int kek = 1;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                ds = mul(ds, add(ret, -x[j]));
                kek = mul(kek, add(x[i], -x[j]));
            }
        }
        ans = add(ans, mul(ds, div(val[i], kek)));
    }
    return ans;
}

const int N = 3000 + 7;

int dp[N][N];
vector <int> g[N];

void dfs(int v)
{
    for (int i = 1; i < N; i++)
    {
        dp[v][i] = 1;
    }
    for (int to : g[v])
    {
        dfs(to);
        for (int j = 1; j < N; j++)
        {
            dp[v][j] = mul(dp[v][j], dp[to][j]);
        }
    }
    for (int i = 2; i < N; i++)
    {
        dp[v][i] = add(dp[v][i], dp[v][i - 1]);
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    dfs(0);
    vector <int> x;
    vector <int> ret;
    for (int i = 0; i <= n; i++)
    {
        x.push_back(i);
        ret.push_back(dp[0][i]);
    }
    cout << ans(x, ret, d) << '\n';
}