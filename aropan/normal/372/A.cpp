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

int n;
vector <int> a;

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
        sort(a.begin(), a.end());

        int l = 0;
        int r = n / 2;
        while (l < r) {
            int c = (l + r) / 2 + 1;
            bool f = true;
            for (int i = 0; i < c; ++i) {
                f &= a[i] * 2 <= a[n - c + i];
            }
            if (f) {
                l = c;
            } else {
                r = c - 1;
            }
        }
        cout << n - l << endl;
    }
	return 0;
}