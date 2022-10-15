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

int find(int x, int *a, int n)
{
    int res = 0;
    for (int i = x; 0 < i; i -= i & -i)
        res = max(res, a[i]);
    return res;
}

void modify(int x, int v, int *a, int n)
{
    for (int i = x; i <= n; i += i & -i)
        a[i] = max(a[i], v);
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
    int a[n + 1];
    memset(a, 0, sizeof(a));

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        modify(x, find(x - 1, a, n) + 1, a, n);
    }
    cout << find(n, a, n) << endl;
	return 0;
}