#include <ctime>
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

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        int a[n];
        bool f[n][n];
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
        
        for (int i = 0; i < 2 * n + p; ++i) {
            int x, y;
            x = y = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (!f[i][j] && (x == y || a[i] + a[j] < a[x] + a[y])) {
                        x = i;
                        y = j;
                    }
                }
            }

            cout << x + 1 << " " << y + 1 << endl;
            a[x] += 1;
            a[y] += 1;
            f[y][x] = f[x][y] = true;
        }
    }
    
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}