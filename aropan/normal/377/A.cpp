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

int n, m, k;
vector <string> s;

void dfs(int x, int y)
{
    if (x < 0 || y < 0 || n <= x || m <= y || s[x][y] != '.' || k == 0) {
        return;
    }
    s[x][y] = ',';
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
    if (k) {
        s[x][y] = 'X';
        k -= 1;
    }
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    while (cin >> n >> m >> k) {
        s.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        int x, y;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (s[i][j] == '.') {
                    x = i;
                    y = j;
                }
        dfs(x, y);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (s[i][j] == ',') {
                    s[i][j] = '.';
                }
        for (int i = 0; i < n; ++i) {
            cout << s[i] << "\n";
        }
    }
	return 0;
}