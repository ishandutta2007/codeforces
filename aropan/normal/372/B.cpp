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


int n, m, k;
vector <string> s;
vector < vector <int> > a;

const int MAXN = 42;
int c[MAXN][MAXN][MAXN][MAXN];

int main(int argc, char **argv)
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    
    cin >> n >> m >> k;
    s.resize(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1;
        --y1;
        
        if (!c[x1][y1][x2][y2]) {
            a.resize(x2 - x1);
            for (int i = 0; i < x2 - x1; ++i) {
                a[i].resize(y2 - y1);
                for (int j = 0; j < y2 - y1; ++j) {
                    a[i][j] = s[i + x1][j + y1] == '0';
                }
            }
            
            vector <int> f;
            vector <int> p;
            vector <int> l, r;
            
            int z = a[0].size();

            f.resize(z, 0);
            l.resize(z, 0);
            r.resize(z, 0);
            p.resize(z, 0);

            for (int i = 0; i < z; ++i)
                p[i] = i;
            
            int ans = 0;
            for (size_t i = 0; i < a.size(); ++i) {
                for (int j = 0; j < z; ++j)
                    if (a[i][j]) {
                        f[j] += 1;
                    } else {
                        f[j] = 0;
                    }
                {
                    vector <int> np;
                    for (int j = 0; j < z; ++j)
                        if (a[i][p[j]]) {
                            np.push_back(p[j]);
                        }
                    for (int j = 0; j < z; ++j)
                        if (!a[i][p[j]]) {
                            np.push_back(p[j]);
                        }
                    p = np;
                }
                for (int j = 0; j < z; ++j) {
                    l[j] = j - 1;
                    r[j] = j + 1;
                }
                
                for (int j = 0; j < z; ++j) {
                    int ll = l[p[j]];
                    int rr = r[p[j]];
    //                cout << p[j] << " " << ll << " " << rr << " = " << (f[p[j]] - max(0 <= ll? f[ll] : 0, rr < z? f[rr] : 0)) * (rr - ll - 1) * (rr - ll) / 2 << endl;
                    int h = f[p[j]] - max(0 <= ll? f[ll] : 0, rr < z? f[rr] : 0);
                    int w = (rr - ll - 1);
                    ans += h * w * (w + 1) / 2;
                    if (0 <= ll) {
                        r[ll] = rr;
                    }
                    if (rr < z) {
                        l[rr] = ll;
                    }
                }
            }
            c[x1][y1][x2][y2] = ans + 1;
        }
        printf("%d\n", c[x1][y1][x2][y2] - 1);
    }
	return 0;
}