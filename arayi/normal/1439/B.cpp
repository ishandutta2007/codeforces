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
    return (a * (a + 1LL)) / 2LL;
}
mt19937 rnd(363542);
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };


const int N = 5e5 + 30;
const lli mod = 998244353;
const ld pi = acos(-1);
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

itn n, m, t, k;
vii g[N];
itn sz[N];
unordered_map <int, int> mp[N];
bool stg(int v)
{
    vii fp;
    for (int p : g[v])
        if (sz[p] >= k - 1) fp.ad(p);
    for (int i = 0; i < fp.size(); i++)
        for (int j = i + 1; j < fp.size(); j++)
            if (!mp[fp[i]][fp[j]]) return 0;
    return 1;
}
void cl()
{
    for (int i = 1; i <= n; i++)
    {
        mp[i].clear();
        g[i].clear();
        sz[i] = 0;
    }
}
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            mp[a][b] = 1;
            mp[b][a] = 1;
            g[a].ad(b);
            g[b].ad(a);
        }
        if (k > 500)
        {
            cout << -1 << endl;
            cl();
            continue;
        }
        queue<int> q, q1;
        for (int i = 1; i <= n; i++){
            sz[i] = g[i].size();
            if (sz[i] < k) q.push(i);
        }
        int qn = n; 
        while (q.size())
        {
            int v = q.front();
            qn--;
            sz[v] = 0;
            q.pop();
            for (auto p : g[v])
            {
                sz[p]--;
                if (sz[p] == k - 1) q.push(p);
            }
        }
        if (qn)
        {
            cout << 1 << " " << qn << endl;
            for (int i = 1; i <= n; i++)
                if (sz[i] >= k) cout << i << " ";
            cl();
            cout << "\n";
            continue;
        }
        for (int i = 1; i <= n; i++) {
            sz[i] = g[i].size();
            if (sz[i] < k - 1) q.push(i);
            else if (sz[i] == k - 1) q1.push(i);
        }
        bool bl = 0;
        while ((int)q.size() + (int)q1.size())
        {
            //cout << "SM" << endl;
            if (q.size())
            {
                int v = q.front();
                sz[v] = 0;
                q.pop();
                for (auto p : g[v])
                {
                    sz[p]--;
                    if (sz[p] == k - 1) q1.push(p);
                    else if (sz[p] == k - 2) q.push(p);
                }
            }
            else
            {
                int v = q1.front();
                q1.pop();
                if (sz[v] < k - 1)
                {
                    continue;
                }
                if (stg(v))
                {
                    cout << 2 << endl;
                    cout << v << " ";
                    for (int p : g[v])
                        if (sz[p] >= k - 1) cout << p << " ";
                    cout << "\n";
                    bl = 1;
                    break;
                }
                q.push(v);
            }
        }
        if (!bl) cout << -1 << endl;
        cl();
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