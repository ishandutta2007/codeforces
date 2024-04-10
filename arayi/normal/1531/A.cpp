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



int n, q;
str a[N];
set<int> s, e;
int t[4 * N], flg[4 * N];
void push(int nd, int d)
{
    flg[nd * 2] += flg[nd];
    flg[nd * 2 + 1] += flg[nd];
    t[nd] += flg[nd] * d;
    flg[nd] = 0;
}
void upd(int l, int r, int v, int nl = 0, int nr = n, int nd = 1)
{
    push(nd, nr - nl + 1);
    if (l > nr || r < nl) return;
    if (l == nl && r == nr)
    {
        flg[nd] += v;
        push(nd, nr - nl + 1);
        return;
    }
    int mid = (nl + nr) / 2;
    upd(l, min(mid, r), v, nl, mid, nd * 2);
    upd(max(mid + 1, l), r, v, mid + 1, nr, nd * 2 + 1);
    t[nd] = t[nd * 2] + t[nd * 2 + 1];
}
int qry(int l, int r, int nl = 0, int nr = n, int nd = 1)
{
    push(nd, nr - nl + 1);
    if (l > nr || r < nl) return 0;
    if (l == nl && r == nr) return t[nd];
    int mid = (nl + nr) / 2;
    return qry(l, min(mid, r), nl, mid, nd * 2) + qry(max(mid + 1, l), r, mid + 1, nr, nd * 2 + 1);
}
int ans(int l, int r, int nd)
{
    if (l == r) return l;
    int mid = (l + r) / 2;
    push(nd * 2, mid - l + 1);
    push(nd * 2 + 1, r - mid);
    if (t[nd * 2 + 1] != r - mid) return ans(mid + 1, r, nd * 2 + 1);
    else return ans(l, mid, nd * 2);
}
int main()
{
    fastio;
    cin >> n;
    a[0] = "blue";
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == "lock")
        {
            e.insert(i);
            if (qry(i, i) == 0) upd(i, n, 1);
        }
        else if (a[i] == "unlock")
        {
            s.insert(i);
            if (qry(i, i) == 1) upd(i + 1, n, -1);
            else upd(i, i, 1);
        }
    }
    cout << a[ans(0, n, 1)] << endl;
    return 0;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int i1;
        str t;
        cin >> i1 >> t;
        if (a[i1] == "lock")
        {
            e.erase(i1);
            int sm = n + 1;
            if (!e.empty() && e.lower_bound(i1) != e.end()) mini(sm, *e.lower_bound(i1));
            if (!s.empty() && s.lower_bound(i1) != s.end()) mini(sm, *s.lower_bound(i1));
            upd(i1, sm - 1, -1);
        }
        else if (a[i1] == "unlock")
        {
            s.erase(i1);
            auto p1 = s.lower_bound(i1), p2 = e.lower_bound(i1);
            if (e.empty() || p2 == e.begin()) upd(i1, i1, -1);
            else if (s.empty() || p1 == s.begin() || *(--p1) < *(--p2))
            {
                int sm = n + 1;
                if (!e.empty() && e.lower_bound(i1) != e.end()) mini(sm, *e.lower_bound(i1));
                if (!s.empty() && s.lower_bound(i1) != s.end()) mini(sm, *s.lower_bound(i1));
                upd(i1 + 1, sm - 1, 1);
            }
            else upd(i1, i1, -1);
        }
        if (t == "lock")
        {
            if (qry(i1, i1) == 0)
            {
                int sm = n + 1;
                if (!e.empty() && e.lower_bound(i1) != e.end()) mini(sm, *e.lower_bound(i1));
                if (!s.empty() && s.lower_bound(i1) != s.end()) mini(sm, *s.lower_bound(i1));
                upd(i1, sm - 1, 1);
            }
            e.insert(i1);
        }
        else if (t == "unlock")
        {
            if (qry(i1, i1) == 0) upd(i1, i1, 1);
            else
            {
                int sm = n + 1;
                if (!e.empty() && e.lower_bound(i1) != e.end()) mini(sm, *e.lower_bound(i1));
                if (!s.empty() && s.lower_bound(i1) != s.end()) mini(sm, *s.lower_bound(i1));
                upd(i1 + 1, sm - 1, -1);
            }
            s.insert(i1);
        }
        a[i1] = t;
        cout << a[ans(0, n, 1)] << "\n";
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