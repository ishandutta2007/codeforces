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


const int N = 2e6 + 30;
const lli mod = 998244353;
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
void maxi(lli& a, lli b)
{
    a = max(a, b);
}



struct el
{
    int l, r, i;
    lli haj, pos;
    el()
    {
        l = r = i = haj = pos = 0;
    }
};

int n, m;int i1 = 1, vrj = 1;
lli b[N], s[N];
priority_queue <pair<lli, pir> > q;
el a[N];
lli cnt(int i, int i1)
{
    lli ret = b[i] - b[a[i1].i];
    ret += a[i1].pos * (s[i] - s[a[i1].i]);
    return ret;
}
int main()
{
    fastio;
    cin >> n >> m;
    a[1].haj = n;
    i1++;
    for (int i = 1; i <= m; i++)
    {
        int A;
        cin >> A;
        s[i] = s[i - 1], b[i] = b[i - 1];
        if (A == 1)
        {
            lli k;
            cin >> k;
            a[i1].haj = a[vrj].pos + a[vrj].haj + k;
            a[i1].i = i;
            vrj = i1++;
            while (q.size()) q.pop();
        }
        else if (A == 2)
        {
            lli k;
            cin >> k;
            a[i1].haj = k;
            a[vrj].r = i1;
            a[i1].l = vrj;
            a[i1].pos = a[vrj].pos + a[vrj].haj;
            a[i1].i = i;
            lli sm = (cnt(i, vrj) + a[vrj].haj - 1LL) / a[vrj].haj;
            q.push(MP(-s[i] - sm, MP(i1, a[i1].l)));
            vrj = i1++;
        }
        else
        {
            cin >> b[i] >> s[i];
            b[i] += b[i - 1], s[i] += s[i - 1];  
        }
        while (q.size() && -q.top().fr <= s[i])
        {
            int u = q.top().sc.fr;
            int v = q.top().sc.sc;
            q.pop();
            if (a[u].l != v) continue;
            a[a[u].l].haj += a[u].haj;
            a[a[u].l].r = a[u].r;
            a[a[u].r].l = a[u].l;
            if (u == vrj) vrj = a[u].l;
            else
            {
                lli sm = cnt(i, a[u].l) - cnt(i, a[u].r);
                if (sm < 0) q.push(MP(0, MP(a[u].r, a[a[u].r].l)));
                else
                {
                    sm = (sm + a[a[u].l].haj - 1LL) / a[a[u].l].haj;
                    q.push(MP(-s[i] - sm, MP(a[u].r, a[a[u].r].l)));
                }
            }
        }
        cout << a[vrj].pos + 1 << " " << cnt(i, vrj) << endl;
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