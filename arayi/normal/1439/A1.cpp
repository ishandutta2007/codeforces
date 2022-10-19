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

int n, m, t;
str s[N];

int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<pir> pat, ans;
        for (int i = 0; i < n; i++) cin >> s[i];
        if (n % 2 && m % 2)
        {
            if (s[n - 1][m - 1] == '1') pat.ad(MP(n - 1, m - 1)), pat.ad(MP(n - 1, m - 2)), pat.ad(MP(n - 2, m - 1));
            for (auto p : pat) s[p.fr][p.sc] = '1' - s[p.fr][p.sc] + '0', ans.ad(p);
            pat.clear();
            for (int i = 0; i < m - 1; i++)
            {
                if (i < m - 2)
                {
                    if (s[n - 1][i] == '1') pat.ad(MP(n - 1, i)), pat.ad(MP(n - 2, i)), pat.ad(MP(n - 2, i + 1));
                }
                else if (s[n - 1][i] == '1') pat.ad(MP(n - 1, i)), pat.ad(MP(n - 2, i)), pat.ad(MP(n - 2, i - 1));
                for (auto p : pat) s[p.fr][p.sc] = '1' - s[p.fr][p.sc] + '0', ans.ad(p);
                pat.clear();
            }
            for (int i = 0; i < n - 1; i++)
            {
                if (i < n - 2)
                {
                    if (s[i][m - 1] == '1') pat.ad(MP(i, m - 1)), pat.ad(MP(i, m - 2)), pat.ad(MP(i + 1, m - 2));
                }
                else if (s[i][m - 1] == '1') pat.ad(MP(i, m - 1)), pat.ad(MP(i, m - 2)), pat.ad(MP(i - 1, m - 2));
                for (auto p : pat) s[p.fr][p.sc] = '1' - s[p.fr][p.sc] + '0', ans.ad(p);
                pat.clear();
            }
        }
        else if (n % 2)
        {
            for (int i = 0; i < m; i++)
            {
                if (i < m - 1)
                {
                    if (s[n - 1][i] == '1') pat.ad(MP(n - 1, i)), pat.ad(MP(n - 2, i)), pat.ad(MP(n - 2, i + 1));
                }
                else if (s[n - 1][i] == '1') pat.ad(MP(n - 1, i)), pat.ad(MP(n - 2, i)), pat.ad(MP(n - 2, i - 1));
                for (auto p : pat) s[p.fr][p.sc] = '1' - s[p.fr][p.sc] + '0', ans.ad(p);
                pat.clear();
            }
        }
        else if (m % 2)
        {
            for (int i = 0; i < n; i++)
            {
                if (i < n - 1)
                {
                    if (s[i][m - 1] == '1') pat.ad(MP(i, m - 1)), pat.ad(MP(i, m - 2)), pat.ad(MP(i + 1, m - 2));
                }
                else if (s[i][m - 1] == '1') pat.ad(MP(i, m - 1)), pat.ad(MP(i, m - 2)), pat.ad(MP(i - 1, m - 2));
                for (auto p : pat) s[p.fr][p.sc] = '1' - s[p.fr][p.sc] + '0', ans.ad(p);
                pat.clear();
            }
        }
        for (int i = 0; i < n - 1; i += 2)
        {
            for (int j = 0; j < m - 1; j += 2)
            {
                vector<pir> mk[2];
                mk[s[i][j] - '0'].ad(MP(i, j));
                mk[s[i + 1][j] - '0'].ad(MP(i + 1, j));
                mk[s[i][j + 1] - '0'].ad(MP(i, j + 1));
                mk[s[i + 1][j + 1] - '0'].ad(MP(i + 1, j + 1));
                while (mk[1].size())
                {
                    if (mk[1].size() >= 3)
                        for (int k = 0; k < 3; k++) pat.ad(mk[1][k]);
                    else
                        pat.ad(mk[1][0]), pat.ad(mk[0][0]), pat.ad(mk[0][1]);
                    for (auto p : pat) s[p.fr][p.sc] = '1' - s[p.fr][p.sc] + '0', ans.ad(p);
                    pat.clear();
                    mk[0].clear(), mk[1].clear();
                    mk[s[i][j] - '0'].ad(MP(i, j));
                    mk[s[i + 1][j] - '0'].ad(MP(i + 1, j));
                    mk[s[i][j + 1] - '0'].ad(MP(i, j + 1));
                    mk[s[i + 1][j + 1] - '0'].ad(MP(i + 1, j + 1));
                }
            }
        }
        cout << ans.size() / 3 << endl;
        for (int i = 0; i < ans.size(); i++)
            ans[i].fr++, ans[i].sc++;
        for (int i = 0; i < ans.size(); i += 3)
            cout << ans[i] << " " << ans[i + 1] << " " << ans[i + 2] << endl;
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