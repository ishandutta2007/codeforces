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
    while (cin >> n) {
        vector <int> a;
        int fs, sc;
        fs = sc = 0;
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            for (int j = 1; j <= m; ++j) {
                int x;
                cin >> x;
                if (2 * j <= m) {
                    fs += x;
                } else
                if ((m & 1) && (m + 1) / 2 == j) {
                    a.push_back(x);
                } else {
                    sc += x;
                }
            }
        }
        sort(a.rbegin(), a.rend());
        for (size_t i = 0; i < a.size(); ++i) {
            ((i & 1)? sc : fs) += a[i];
        }
        cout << fs << " " << sc << endl;
    }

	return 0;
}