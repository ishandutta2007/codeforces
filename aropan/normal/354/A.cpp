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
    int n;
    long long l, r, ql, qr;
    cin >> n;
    cin >> l >> r >> ql >> qr;
    long long a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    
    
    long long ans = (long long)1e+18;
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans,
            a[i] * l + (a[n] - a[i]) * r + 
            max(0, i - (n - i) - 1) * ql +
            max(0, (n - i) - i - 1) * qr
        );
    }
    cout << ans << endl;
	return 0;
}