#include <queue>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)


const int MOD = 1000000007;

void add(int &x, long long d)
{
    x += d % MOD;
    if (x >= MOD)
        x -= MOD;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    
    int n;
    cin >> n;
    int f[n + 1], a[n + 1];
    memset(f, 0, sizeof(f));
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]] = true;
    }
/*    
    int res = 0;
    int p[n + 1];
    for (int i = 1; i <= n; i++)
        p[i] = i;
    do
    {
        bool flg = true;
        for (int i = 1; i <= n; i++)
            flg &= p[i] != i && (a[i] == -1 || a[i] == p[i]);
        res += flg;
    } while (next_permutation(p + 1, p + n + 1));
//*/    
    int m = 0;
    for (int i = n; i >= 1; i--)
        if (f[i])
        {
            n--;
        }
        else
        {
            m += a[i] == -1;
        }
    int g[n + 1][m + 1];
    memset(g, 0, sizeof(g));
    g[n][m] = 1;
/*    
    cout << n << " " << m << endl;
//*/
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            if (g[i][j])
            {
                if (i > j) add(g[i - 1][j - 1], g[i][j] * (long long)(i - j));
                if (j > 1) add(g[i - 1][j - 2], g[i][j] * (long long)(j - 1));
            }

    int ans = g[0][0];
    int F = 1;
    for (int i = 1; i <= n; i++)
    {
        F = (F * (long long)i) % MOD;
        add(ans, F * (long long)g[i][0]);
    }
//    assert(res == ans);
    cout << ans << endl;
	return 0;
}