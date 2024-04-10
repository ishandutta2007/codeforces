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

#define left mleft
#define right mright

const int MAXT = 10000000;
const int MAXN = 150007;

int left[MAXT], right[MAXT], f[MAXT], g[MAXT];
int a[MAXN];
int n, m, h, k;
int root = 0;


void modify(int &curr, int l, int r, int v, int d)
{
    if (curr == 0)
    {
        curr = ++k;
        left[curr] = right[curr] = f[curr] = g[curr] = 0;
    }
    
    if (l == r)
    {
        f[curr] += d;
        g[curr] = f[curr];
        return;
    }
    
    f[curr] += d;
    
    int c = (l + r) / 2;
    if (v <= c)
        modify(left[curr], l, c, v, d);
    else
        modify(right[curr], c + 1, r, v, d);
        
    g[curr] = 0;
    g[curr] = min(g[curr],
        left[curr] == 0? 0 : g[left[curr]]);
        
    g[curr] = min(g[curr],
        (left[curr] == 0? 0 : f[left[curr]]) + (right[curr] == 0? 0 : g[right[curr]]));
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        modify(root, 1, h, max(h - x, 1), 1);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        
        modify(root, 1, h, a[i], -1);
        if (i >= m)
        {
            ans += g[root] >= 0;
            modify(root, 1, h, a[i - m + 1], 1);
        }
    }
    cout << ans << endl;
	return 0;
}