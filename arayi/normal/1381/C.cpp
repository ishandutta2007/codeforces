//Arayi
//#define _CRT_SECURE_NO_WARNINGS
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
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1, 0 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1, 0 };


const int N = 3e5 + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
const ld e = 1e-13;

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
struct pt
{
    lli x, y;
    int ind;
    int bl;
    bool operator==(const pt& a)
    {
        return ind == a.ind;
    }
    bool operator<(const pt& b)
    {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
};





int t, n;
int x, y, a[N];
int col[N];
vector <int> b[N];
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> y;
        int x1 = x, y1 = y;
        vector <int> pat(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[a[i]].ad(i);
        }
        priority_queue <pir > fp;
        int ch = n + 1;
        for (int i = 1; i <= n + 1; i++)
        {
            fp.push(MP((int)b[i].size(), i));
            if (b[i].empty()) ch = i;
        }
        for (int i = 0; i < x; i++)
        {
            itn sm = fp.top().sc;
            pat[b[sm].back()] = sm;
            b[sm].pop_back();
            fp.pop();
            fp.push(MP((int)b[sm].size(), sm));
        }
        vector <pir > ar, er;
        for (int i = 1; i <= n + 1; i++)
        {
            for (auto p : b[i])
            {
                ar.ad(MP(i, p));
                er.ad(MP(i, p));
            }
        }
        reverse(all(er));
        int i1 = -1, i2 = -1;
        for (int i = 0; i < ar.size(); i++)
        {
            if (ar[i].fr == er[i].fr)
            {
                i2 = i;
                if (i1 == -1) i1 = i;
            }
        }
        if (i1 != -1)
        {
            int sk = min(i1, i2 - i1 + 1);
            for (int i = i1; i < i1 + sk; i++)
            {
                if (er[i].fr == ar[i - i1].fr || er[i].fr == er[i - i1].fr)
                {
                    sk = i - i1;
                    break;
                }
                swap(er[i], er[i - i1]);
                
            }
            for (int i = i1 + sk; i <= i2; i++)
            {
                swap(er[i], er[(int)er.size() - 1 + i1 + sk - i]);
            }
        }

        bool bl = false;
        for (int i = 0; i < y - x; i++)
        {
            if (ar[i].fr == er[i].fr)
            {
                if (y - x < (int)ar.size())
                    pat[ar[i].sc] = ch, y++;
                else
                    bl = true;
            }
            else
            {
                pat[ar[i].sc] = er[i].fr;
            }
        }
        for (int i = y - x; i < (int)ar.size(); i++)
        {
            pat[ar[i].sc] = ch;
        }
        for (int i = 1; i <= n + 1; i++) b[i].clear();
        if (bl) cout << "NO\n";
        else
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                if (pat[i] == a[i]) x1--;
            }
            for (int i = 0; i <= n + 1; i++)
            {
                col[i] = 0;
            }
            for (int i = 0; i < n; i++)
            {
                col[a[i]]++;
            }
            for (int i = 0; i < n; i++)
            {
                if (col[pat[i]]) y1--, col[pat[i]]--;
            }
            if (x1 || y1) assert(0);
            for (int i = 0; i < n; i++)
            {
                cout << pat[i] << " ";
            }
            cout << endl;
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