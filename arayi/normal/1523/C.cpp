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



int n, tt;
int t[4 * N], flg[4 * N];
void push(int nd)
{
    t[nd] += flg[nd];
    flg[nd * 2] += flg[nd];
    flg[nd * 2 + 1] += flg[nd];
    flg[nd] = 0;
}
void upd(int l, int r, lli v, int nl = 0, int nr = n, int nd = 1)
{
    push(nd);
    if (l > nr || r < nl) return;
    if (l == nl && r == nr)
    {
        flg[nd] += v;
        push(nd);
        return;
    }
    int mid = (nl + nr) / 2;
    upd(l, min(mid, r), v, nl, mid, nd * 2);
    upd(max(mid + 1, l), r, v, mid + 1, nr, nd * 2 + 1);
    t[nd] = t[nd * 2] + t[nd * 2 + 1];
}
lli qry(int l, int r, int nl = 0, int nr = n, int nd = 1)
{
    push(nd);
    if (l > nr || r < nl) return 0;
    if (l == nl && r == nr) return t[nd];
    int mid = (nl + nr) / 2;
    return qry(l, min(mid, r), nl, mid, nd * 2) + qry(max(mid + 1, l), r, mid + 1, nr, nd * 2 + 1);
}

void slv()
{
    cin >> n;
    vector<vii > fp;
    vii nw;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1) nw.ad(1), fp.ad(nw);
        else
        {
            while (1)
            {
                if (fp.back().back() != x - 1) fp.pop_back();
                else
                {
                    fp.back().back()++;
                    nw = fp.back();
                    break;
                }
            }
        }
        for (int j = 0; j < nw.size() - 1; j++) cout << nw[j] << ".";
        cout << nw.back() << endl;
    }
}
int main()
{
    fastio;
    cin >> tt;
    while (tt--)
    {
        slv();
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