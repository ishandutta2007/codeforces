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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int MAXN = 1000007;

long long a[MAXN];
long long l[MAXN], c[MAXN], x[MAXN];
long long ans[MAXN];
int n, m;

long long get(long long n)
{
    if (n < MAXN && ans[n]) {
        return ans[n];
    }
    long long res;
    int i = lower_bound(a, a + m + 1, n) - a;
    if (x[i]) {
        res = x[i];
    } else {
        res = get((n - a[i - 1] - 1) % l[i] + 1);
    }
    
    if (n < MAXN) {
        ans[n] = res;
    }
    return res;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    cin >> m;
    a[0] = 0;
    for (int i = 1; i <= m; ++i)
    {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> x[i];
            a[i] = a[i - 1] + 1;
        } else {
            cin >> l[i] >> c[i];
            a[i] = a[i - 1] + l[i] * c[i];
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        if (i) {
            cout << " ";
        }
        cout << get(x);
    }
    cout << endl;
    
    
	return 0;
}