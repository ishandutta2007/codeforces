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
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 2002;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const char dc[4] = {'^', '>', 'v', '<'};

string s[MAXN];
int c[MAXN][MAXN];
int n, m;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        queue < pair <int, int > > q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '*') {
                    continue;
                }
                c[i][j] = 0;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    c[i][j] += (0 <= x && x < n && 0 <= y && y < m && s[x][y] == '.');
                }
                if (((i + j) & 1) == 0 && c[i][j] == 1) {
                    q.push(make_pair(i, j));
                }
            }
        }
        while (q.size()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (0 <= x && x < n && 0 <= y && y < m && s[x][y] == '.') {
                    s[i][j] = dc[(k + 2) & 3];
                    s[x][y] = dc[k];
                    for (int l = 0; l < 4; ++l) {
                        x += dx[l];
                        y += dy[l];
                        if (0 <= x && x < n && 0 <= y && y < m && s[x][y] == '.') {
                            if (--c[x][y] == 1) {
                                q.push(make_pair(x, y));
                            }
                        }
                        x -= dx[l];
                        y -= dy[l];
                    }
                }
            }
        }

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ok &= s[i][j] != '.';
            }
        }
        if (!ok) {
            cout << "Not unique" << endl;
        } else {
            for (int i = 0; i < n; ++i) {
                cout << s[i] << "\n";
            }
        }
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}