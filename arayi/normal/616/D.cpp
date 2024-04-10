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
#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
#define itn int
#define pir pair<int, int> 
#define all(x) (x).begin(), (x).end()
#define str string
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
    return (a * (a + 1LL)) / 2;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1 };


const int N = 3e6 + 30;
const lli mod = 998244353;
const ld pi = acos(-1);
const int T = 238;
const ld e = 1e-6;

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



int n, k;
int a[N], col[N];
bool stg(int x)
{
    int sm = 0;
    for (int i = 0; i < x; i++)
    {
        col[a[i]]++;
        if (col[a[i]] > 1) continue;
        sm++;
    }
    if (sm <= k) return true;
    int l = 0, r = x - 1;
    while (r < n - 1)
    {
        col[a[l]]--;
        if (col[a[l]] == 0) sm--;
        l++;
        r++;
        col[a[r]]++;
        if (col[a[r]] == 1) sm++;
        if (sm <= k) return true;
    }
    return false;
}
void maq()
{
    for (int i = 0; i < n; i++)
        col[a[i]] = 0;
}
int main()
{
    fastio;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    itn l = 1, r = n, ans = 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (stg(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
        maq();
    }
    //cout << ans << endl;
    int x = ans;
    int sm = 0;
    for (int i = 0; i < x; i++)
    {
        col[a[i]]++;
        if (col[a[i]] > 1) continue;
        sm++;
    }
    l = 0, r = x - 1;
    if (sm <= k) return cout << l + 1 << " " << l + ans, 0;
    
    while (r < n - 1)
    {
        col[a[l]]--;
        if (col[a[l]] == 0) sm--;
        l++;
        r++;
        col[a[r]]++;
        if (col[a[r]] == 1) sm++;
        if (sm <= k) return cout << l + 1 << " " << l + ans, 0;
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