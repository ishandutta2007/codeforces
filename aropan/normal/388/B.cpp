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
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

const int MAXN = 1007;

typedef pair < int, pair <int, int> > mpair;
#define mpair(x, y, z) make_pair(x, make_pair(y, z))

int K;
map < mpair, int> m;
bool ans[MAXN][MAXN];

int rec(int x, int d = 1, int t = 1)
{
    mpair p = mpair(x, d, t);
    if (!m.count(p)) {
        int k = m.size() + 1;
        m[p] = k;
        int y = rec(x >> 1, d + 1, 1);
        ans[y][k] = true;
        if (x > 1) {
            y = rec((x + 1) >> 1, d + 1, x & 1);
            ans[y][k] = true;
        }
    }
    return m[p];
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    
    while (cin >> K) {
        m.clear();
        memset(ans, 0, sizeof(ans));
        m[mpair(0, 33, 1)] = 1;
        rec(K);
        
        int n = m.size();
        cout << n << endl;
        for (int i = 1; i <= n; ++i) {
            
            for (int j = 1; j <= n; ++j) {
                cout << (ans[i][j] || ans[j][i]? 'Y' : 'N');
            }
            cout << endl;
        }
    }
	return 0;
}