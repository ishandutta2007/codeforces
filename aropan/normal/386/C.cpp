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

const int MAXN = 3 * 100007;
const int MAXA = 28;

char s[MAXN];
int a[MAXA], p[MAXA];
long long ans[MAXA];

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    scanf("%s", s);
    for (int i = 0; i < MAXA; ++i) {
        p[i] = i;
        a[i] = 0;
    }
    
    for (int i = 0; s[i]; ++i) {
        int c = MAXA;
        int t = s[i] - 'a';
        for (int j = MAXA - 1; j >= 0; --j)
            if (t != p[j]) {
                p[--c] = p[j];
            }
        p[--c] = t;
        a[t] = i + 1;

        for (int j = 1; j < MAXA; ++j) {
            ans[j - 1] += a[p[j - 1]] - a[p[j]]; 
        }
    }
    int m = 0;
    while (ans[m]) {
        ++m;
    }
    cout << m << endl;
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << "\n";
    }
    
	return 0;
}