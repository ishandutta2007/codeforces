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

const int MAXN = 20;
const int MAXM = 1 << MAXN;
const int INF = (int)1e+9;

int f[MAXN][MAXM];
char c[MAXN];
int t[MAXN];
vector <int> a;
int n, m;


int dfs(int ind, int msk)
{
    if (ind == m) {
        return 0;
    }

    if (f[ind][msk] != INF) {
        return f[ind][msk];
    }
    
    int &res = f[ind][msk];
    
    res = t[ind] == 1? -INF : INF;
    
    for (int i = 0; i < n; ++i) {
        if (((1 << i) & (msk)) == 0) {
            int v = dfs(ind + 1, msk | (1 << i));
            if (c[ind] == 'p') {
                v += a[i] * (t[ind] == 1? 1 : -1);
            }
            
            if (t[ind] == 1)
                res = max(res, v);
            else
                res = min(res, v);

            if (c[ind] == 'p') {
                break;
            }
        }
    }
/*    
    if (c[ind] == 'b') {
        int v = dfs(ind + 1, msk);
        if (t[ind] == 1)
            res = max(res, v);
        else
            res = min(res, v);
    }
//*/
    return res;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    
    while (cin >> n) {
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        cin >> m;
        n = m;
        a.resize(n);
        for (int i = 0; i < m; ++i) {
            cin >> c[i] >> t[i];
        }
        for (int i = 0; i < MAXN; ++i)
            for (int j = 0; j < MAXM; ++j)
                f[i][j] = INF;
        
        cout << dfs(0, 0) << "\n";
    }
	return 0;
}