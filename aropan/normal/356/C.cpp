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

const int INF = (int)1e+9 + 7;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    
    int n;
    while (cin >> n)
    //for (int t = 0; t < 1000; t++)
    {
        int s = 0;
        vector <int> _k;
        _k.resize(5, 0);
//        n = rand() % 1000 + 1;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
//            x = rand() % 4 + 1;
//            cout << x << " ";
//            assert(0 <= x && x <= 4);
            s += x;
            _k[x] += 1;
        }
//        cout << endl;

        int ans = INF;
        for (int i = 0; i <= s / 4; i++)
        {
            if ((s - i * 4) % 3)
                continue;
            int a = i;
            int b = (s - a * 4) / 3;
            if (a + b > n)
                continue;
            int r = 0, x;
            vector <int> k = _k;
            if (a > k[4])
            {
                x = min(min(k[3], k[1]), a - k[4]);
                k[1] -= x;
                k[3] -= x;
                k[4] += x;
                r += x;

                x = min(min(k[3] / 2, k[2]), (a - k[4]) / 2);
                k[2] -= x;
                k[3] -= 2 * x;
                k[4] += 2 * x;
                r += 2 * x;

                x = min(min(k[2], k[1] / 2), a - k[4]);
                k[1] -= 2 * x;
                k[2] -= x;
                k[4] += x;
                r += 2 * x;

                x = min(k[2] / 2, a - k[4]);
                k[2] -= 2 * x;
                k[4] += x;
                r += 2 * x;

                x = min(k[1] / 4, a - k[4]);
                k[1] -= 4 * x;
                k[4] += x;
                r += 3 * x;
            }

            assert(a <= k[4] || (k[1] == 0 && k[2] == 0));
            if (a > k[4])
                continue;
                
            k[1] += k[4] - a;
            k[3] += k[4] - a;
            k[4] = a;

            if (b > k[3])
            {
                x = min(min(k[1], k[2]), b - k[3]);
                k[1] -= x;
                k[2] -= x;
                k[3] += x;
                r += x;

                x = min(k[2] / 3, (b - k[3]) / 2);
                k[2] -= 3 * x;
                k[3] += 2 * x;
                r += 2 * x;

                x = min(k[1] / 3, b - k[3]);
                k[1] -= 3 * x;
                k[3] += x;
                r += 2 * x;
            }
//            cout << k[0] << " " << k[1] << " " << k[2] << " " << k[3] << " " << k[4] << endl;
//            cout << a << " " << b << " " << r << endl;
//            assert (a == k[4] && b == k[3]);
            if (a == k[4] && b == k[3])
            {
                ans = min(ans, r);
            }
            
        }
        cout << (ans == INF? -1 : ans) << endl;
    }
	return 0;
}