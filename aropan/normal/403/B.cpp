#include <ctime>
#include <queue>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

const int MAXN = 5003;
const int SIZE = 1000000;

map <int, int> S;
int f[MAXN][MAXN];

const int INF = (int)1e+9 + 7;

int get(int n, const set <int> &s, int i = 2)
{
    if (n == 1) {
        return 0;
    }

    if (S.count(n)) {
        return S[n];
    }
    
    int &res = S[n];
    res = 0;

    while (i * i <= n) {
        if (n % i == 0) {
            int t = 0;
            do {
                n /= i;
                t += 1;
            } while (n % i == 0);
            res = t * (1 - s.count(i) * 2) + get(n, s, i + 1);
            return res;
        }
        ++i;
    }

    res = 1 - s.count(n) * 2;
    return res;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    
    int n, m;
    while (cin >> n >> m) {
        S.clear();

        int a[n + 1];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        set <int> b;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            b.insert(x);
        }
        
        int g[n + 1];
        a[n] = 1;
        for (int i = 0; i <= n; ++i) {
            g[i] = a[i];
            i && (g[i] = gcd(g[i - 1], g[i]));
        }
        
        f[n][n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int mx = -INF;
            for (int j = i + 1; j <= n; ++j) {
                f[i][j] = f[i + 1][j] + get(a[i] / g[j], b);
                mx = max(f[i + 1][j], mx);
            }
            f[i][i] = mx + get(a[i] / g[i], b);
        }
        
        int ans = -INF;
        for (int i = 0; i <= n; ++i) {
            ans = max(ans, f[0][i]);
        }

        cout << ans << endl;
    }
    
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}