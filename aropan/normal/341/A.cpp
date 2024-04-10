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
    cin >> n;
    long long a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, a + n + 1);
    unsigned long long ans = 0;
    for (int i = 1; i < n; i++)
        ans += 2ULL * i * (unsigned long long )(n - i) * (a[i + 1] - a[i]);
    for (int i = 1; i <= n; i++)
        ans += a[i];
    unsigned long long g = gcd(ans, (unsigned long long)n);
    cout << ans / g << " " << n / g << endl;
/*
    cout << ans << endl;
    int p[n];
    for (int i = 0; i < n; i++)
        p[i] = i + 1;

    long double res = 0;
    do
    {
        res += a[p[0]];
        for (int i = 1; i < n; i++)
            res += abs(a[p[i - 1]] - a[p[i]]);
    } while (next_permutation(p, p + n));
    for (int i = 2; i < n; i++)
        res /= i;
    cout << res << endl;
//*/    
	return 0;
}