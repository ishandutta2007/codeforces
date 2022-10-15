#include <ctime>
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

const int MAXN = 2003;
const int BLOCK = 32;

unsigned int h[MAXN][MAXN / BLOCK + 1];
unsigned int v[MAXN][MAXN / BLOCK + 1];
queue < pair <int, int> > q;
int a[MAXN][MAXN];

void add(int i, int j)
{
    h[i][j / BLOCK] |= (unsigned int)(1 << (j % BLOCK));
    v[j][i / BLOCK] |= (unsigned int)(1 << (i % BLOCK));
    q.push(make_pair(i, j));
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

    int n, m;
    while (cin >> n) {
        memset(h, 0, sizeof(h));
        memset(v, 0, sizeof(v));
        memset(a, 0, sizeof(a));
        m = (n + BLOCK - 1) / BLOCK;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                if (x) {
                    add(i, j);
                }
            }
        }
        
        int total = 0;
        while (q.size()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            ++total;
            
            for (int k = 0; k < m; ++k) {
                unsigned int msk = (v[x][k] | v[y][k]) ^ v[y][k];
                if (msk) {
                    for (int i = 0; msk; msk >>= 1, ++i) {
                        if (msk & 1) {
                            add(k * BLOCK + i, y);
                        }
                    }
                }
            }
            
            for (int k = 0; k < m; ++k) {
                unsigned int msk = (h[x][k] | h[y][k]) ^ h[x][k];
                if (msk) {
                    for (int i = 0; msk; msk >>= 1, ++i) {
                        if (msk & 1) {
                            add(x, k * BLOCK + i);
                        }
                    }
                }
            }
        }
        
        bool answer = total == n * n;
        cout << (answer? "YES" : "NO") << endl;
    }
    
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}