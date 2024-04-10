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
    return (a * (a - 1LL)) / 2;
}
mt19937 rnd(363542);
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };


const int N = 3e5 + 30;
const lli mod = 1e15 + 7;
const ld pi = acos(-1);
const int T = 550;

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

template <class T>
void maxi(T& a, T b)
{
    a = max(a, b);
}



int n, q;
lli t[4 * N], flg[4 * N], sum;
void push(int nd)
{
    t[nd] += flg[nd];
    flg[nd * 2] += flg[nd];
    flg[nd * 2 + 1] += flg[nd];
    flg[nd] = 0;
}
void upd(int l, int r, lli x, int nl = 0, int nr = n - 1, int nd = 1)
{
    push(nd);
    if (l > nr || r < nl) return;
    if (l == nl && r == nr)
    {
        flg[nd] += x;
        push(nd);
        return;
    }
    int mid = (nl + nr) / 2;
    upd(l, min(mid, r), x, nl, mid, nd * 2);
    upd(max(mid + 1, l), r, x, mid + 1, nr, nd * 2 + 1);
}
lli qry(int q, int l = 0, int r = n - 1, int nd = 1)
{
    push(nd);
    if (q > r || q < l) return 0;
    if (l == r) return t[nd];
    int mid = (l + r) / 2;
    return qry(q, l, mid, nd * 2) + qry(q, mid + 1, r, nd * 2 + 1);
}
lli t1[4 * N];
void upd1(int q, lli x, int nl = 0, int nr = n - 1, int nd = 1)
{
    if (q > nr || q < nl) return;
    if (nl == nr)
    {
        t1[nd] = x;
        return;
    }
    int mid = (nl + nr) / 2;
    upd1(q, x, nl, mid, nd * 2);
    upd1(q, x, mid + 1, nr, nd * 2 + 1);
    t1[nd] = max(t1[nd * 2], t1[nd * 2 + 1]);
}
lli qry1(int l, int r, int nl = 0, int nr = n - 1, int nd = 1)
{
    if (l > nr || r < nl) return LLONG_MIN;
    if (l == nl && r == nr) return t1[nd];
    int mid = (nl + nr) / 2;
    return max(qry1(l, min(mid, r), nl, mid, nd * 2), qry1(max(mid + 1, l), r, mid + 1, nr, nd * 2 + 1));
}
lli t2[4 * N];
void upd2(int q, lli x, int nl = 0, int nr = n - 1, int nd = 1)
{
    if (q > nr || q < nl) return;
    if (nl == nr)
    {
        t2[nd] = x;
        return;
    }
    int mid = (nl + nr) / 2;
    upd2(q, x, nl, mid, nd * 2);
    upd2(q, x, mid + 1, nr, nd * 2 + 1);
    t2[nd] = max(t2[nd * 2], t2[nd * 2 + 1]);
}
lli qry2(int l, int r, int nl = 0, int nr = n - 1, int nd = 1)
{
    if (l > nr || r < nl) return LLONG_MIN;
    if (l == nl && r == nr) return t2[nd];
    int mid = (nl + nr) / 2;
    return max(qry2(l, min(mid, r), nl, mid, nd * 2), qry2(max(mid + 1, l), r, mid + 1, nr, nd * 2 + 1));
}
void sm(int i)
{
    if (i == 0 || i == n - 1) return;
    lli a = max(0LL, qry(i - 1) - qry(i)), b = max(0LL, qry(i + 1) - qry(i));
    //if (i == 2) cout << a << " " << b << endl;
    upd1(i, -2LL * min(a, b));
    upd2(i, -2LL * (a + b));
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        lli x;
        cin >> x;
        upd(i, i, x);
        if (i) sum += abs(x - qry(i - 1));
    }
    for (int i = 0; i < n; i++)
        sm(i);
    cin >> q;
    while (q--)
    {
        int A, l, r;
        lli x;
        cin >> A >> l >> r >> x;
        l--, r--;
        if (A == 1)
        {
            //cout << qry2(2, 2) << endl;
            lli pat = -2LL * x;
            if (l == 0) maxi(pat, -abs(qry(0) - qry(1)) + abs(qry(0) + x - qry(1))), l++;
            if (r == n - 1) maxi(pat, abs(qry(r) + x - qry(r - 1)) - abs(qry(r) - qry(r - 1))), r--;
            if(r >= l) maxi(pat, qry1(l, r)), maxi(pat, qry2(l, r) + 2LL * x);
            cout << sum + pat << endl;
        }
        else
        {
            if (l) sum -= abs(qry(l) - qry(l - 1));
            if (r < n - 1) sum -= abs(qry(r) - qry(r + 1));
            upd(l, r, x);
            if (l) sum += abs(qry(l) - qry(l - 1));
            if (r < n - 1) sum += abs(qry(r) - qry(r + 1));
            sm(l);
            if(l) sm(l - 1);
            sm(r);
            if(r < n - 1) sm(r + 1);
            //cout << sum << endl;
        }
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