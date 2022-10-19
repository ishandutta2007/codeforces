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



int n, k;
str s;
int pr[N][20], e[N][20];
int a[N];
bool stg(int md)
{
    //cout << md << endl;
    for (int j = 0; j < k; j++)
    {
        e[n][j]=e[n+1][j]=n+1;
        for (int i = 0; i < n; i++)
        {
            if(i>n-md+1)
            {
                e[i][j]=n+1;
                continue;
            }
            int sm = pr[i+md-1][j]+pr[i+md-1][k];
            if(i) sm-=pr[i-1][j]+pr[i-1][k];
            if(sm == md) e[i][j]=i;
            else e[i][j]=n+1; 
        }
        for (int i = n - 1; i >= 0; i--)
            e[i][j]=min(e[i][j], e[i+1][j]);
    }
    a[0] = 0;
    for (int x = 1; x < (1<<k); x++)
    {
        int ret = n + 1;
        for (int i = 0; i < k; i++)
            if((1<<i)&x) ret=min(ret, e[a[x-(1<<i)]][i] + md);
        a[x] = ret;
    }
    if(a[(1<<k)-1]>n) return false;
    return true;
}
int main()
{
    fastio;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if(i)
        {
            for (int j = 0; j <= k; j++)
                pr[i][j]=pr[i-1][j];
        }
        if(s[i]=='?') pr[i][k]++;
        else pr[i][s[i]-'a']++;
    }
    int l = 0, r = n, ans = 0;
    while(l <= r)
    {
        int md = (l + r)/2;
        if(stg(md)) l = md + 1, ans = md;
        else r = md-1;
    }
    cout << ans << endl;
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