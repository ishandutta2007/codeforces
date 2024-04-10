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

const int MAXX = 1000002;

int s[MAXX];

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    
    int n, k;
    while (cin >> n >> k)
    {
        memset(s, 0, sizeof(s));
        int x;
        int m = (int)1e+9;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            m = min(m, x);
            s[max(x - k, 1)] += 1;
            s[x + 1] -= 1;
        }
        
        if (m < k + 1)
        {
            cout << m << endl;
            continue;
        }
        
        for (int i = 1; i < MAXX; i++)
            s[i] += s[i - 1];

        int ans = k + 1;
        for (int i = k + 2; i < MAXX; i++)
        {
            int m = 0;
            for (int j = i; j < MAXX; j += i)
                m += s[j];
            if (m == n)
                ans = i;
        }
        cout << ans << endl;
    }
	return 0;
}