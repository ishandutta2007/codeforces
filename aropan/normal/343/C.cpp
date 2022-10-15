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
    int n, m;
    while (cin >> n >> m)
    {
        long long h[n], p[m];
        for (int i = 0; i < n; i++)
            cin >> h[i];
        for (int i = 0; i < m; i++)
            cin >> p[i];
        long long l = 0, r = (long long)1e+15;
        while (l < r)
        {
            long long c = (l + r) / 2;
            int j = 0;
            for (int i = 0; i < n && j < m; i++)
            {
                long long f = p[j];
                while (j < m && min(abs(h[i] - f), abs(h[i] - p[j])) + p[j] - f <= c)
                    j++;
            }
            if (j == m)
            {
                r = c;
            } else {
                l = c + 1;
            }
        }
        cout << r << "\n";
    }

	return 0;
}