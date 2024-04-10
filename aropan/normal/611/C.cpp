#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
vector <string> a;
vector < vector <int> > s;

bool empty(int x, int y) {
    if (x < 0 || n <= x || y < 0 || m <= y) {
        return false;
    }
    return a[x][y] == '.';
}


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    cin >> n >> m;
    a.resize(n);
    s = vector < vector <int> >(n + 1, vector <int> (m + 1, 0));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c = 0;
            if (empty(i, j)) {
                for (int d = 0; d < 4; ++d) {
                    c += empty(i + dx[d], j + dy[d]);
                }
            }
            s[i + 1][j + 1] = c;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    int k;
    cin >> k;
    while (k--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int answer = s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1];
        --r1;
        --r2;
        --c1;
        --c2;
        for (int i = c1; i <= c2; ++i) {
            answer -= empty(r1, i) && empty(r1 - 1, i);
            answer -= empty(r2, i) && empty(r2 + 1, i);
        }

        for (int i = r1; i <= r2; ++i) {
            answer -= empty(i, c1) && empty(i, c1 - 1);
            answer -= empty(i, c2) && empty(i, c2 + 1);
        }
        cout << answer / 2 << "\n";
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}