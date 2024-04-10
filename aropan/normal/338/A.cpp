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

const int MOD = 1000000009;

long long powmod(long long a, long long b, long long m)
{
    if (b == 0)
        return 1 % m;
    long long r = powmod(a, b >> 1, m);
    (r *= r) %= m;
    return b & 1? a * r % m : r;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    
    long long n, m, k;
    while (cin >> n >> m >> k)
    {
        long long f = n / k;
        long long t = max(m - (n - f), 0LL);
        cout << (((powmod(2, t + 1, MOD) - 2) * k + m - t * k) % MOD + MOD) % MOD << endl;
    }
	return 0;
}