//Arayi
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>   
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cassert>
#include <chrono>
#include <random>
#include <complex>

#define fr first
#define sc second

#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jigglypuff
#define ld long double
#define itn int
#define pir pair<int, int>
#define all(x) (x).begin(), (x).end()
#define str string
#define enl endl
#define en endl
#define cd complex<long double>
#define vcd vector<cd>
#define vii vector<int>
#define vlli vector<lli>
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x, ld y1, ld x2, ld y2)
{
    return sqrt((x - x2) * (x - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
    return (a * (a + 1LL)) / 2;
}
mt19937 rnd(363542);
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };


const int N = 1e6 + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 200;

lli bp(lli a, lli b = mod - 2LL)
{
    lli ret = 1;
    while (b)
    {
        if (b & 1) ret *= a, ret %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}
ostream& operator<<(ostream& c, pir a)
{
    c << a.fr << " " << a.sc;
    return c;
}
template<class T>
void maxi(T& a, T b)
{
    a = max(a, b);
}
template <class T>
void mini(T& a, T b)
{
    a = min(a, b);
}



int n, m, q;
int p[N], col[N], qn[N];
int gp(int x)
{
    if(x == p[x]) return x;
    return p[x] = gp(p[x]);
}
vii g[N], pat[N];
int dp[N][2];
void dfs(int v, int par)
{
    p[v]=par;
    for(auto p1 : g[v])
    {
        if(p1 == par) continue;
        dfs(p1, v);
    }
}
void dfs1(int v, int par)
{
    int sum = 0;
    int qn = 0;
    for(auto p : g[v])
    {
        if(p==par) continue;
        dfs1(p,v);
        if(!col[p]) sum += dp[p][0];
        else sum+=dp[p][1], qn++;
    }
    dp[v][0] = sum+(qn+1)/2;
    dp[v][1]=sum+qn/2;
}
int main()
{
    fastio;
    cin >> n >> m;
    //cout << "SM"<<endl;
    for (int i = 1; i <= n; i++) p[i]=i;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if(gp(a) == gp(b)) continue;
        g[a].ad(b);
        g[b].ad(a);
        p[gp(a)]= gp(b);
    }
    dfs(1, 0);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        while (a != 1)
        {
            col[a]^=1;
            pat[i].ad(a);
            a=p[a];
        }
        vii sm;
        while(b != 1)
        {
            col[b]^=1;
            sm.ad(b);
            b=p[b];
        }
        int x = 1;
        while (!pat[i].empty() && !sm.empty() && pat[i].back() == sm.back()) x = sm.back(), pat[i].pop_back(), sm.pop_back();
        pat[i].ad(x);
        while (sm.size()) pat[i].ad(sm.back()), sm.pop_back();
    }
    for (int i = 1; i <= n; i++)
        if(col[i]) qn[p[i]]++;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if(!qn[i] && col[i]) ans++;
    }
    if(ans == 0)
    {
        cout << "YES\n";
        for (int i = 0; i < q; i++)
        {
            cout << pat[i].size() << endl;
            for(auto p : pat[i]) cout << p << " ";
            cout << endl;
        }
    }
    else
    {
        dfs1(1,0);
        cout << "NO\n" << dp[1][0] << endl;
    }
    return 0;
}

/*
    __
  *(><)*
    \/ /
    ||/
  --||
    ||
    /\
   /  \
  /    \

*/