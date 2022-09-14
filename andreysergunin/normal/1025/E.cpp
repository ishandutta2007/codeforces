#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN = 55;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct Move {
    int x1, y1, x2, y2;
};

void write(vector<vector<int>> &b) {
    for (int i = 0; i < sz(b); ++i) {
        for (int j = 0; j < sz(b); ++j) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void move(int x, int y, int t, vector<vector<int>> &b, vector<Move> &result) {
    // assert(x < n && y < n && x >= 0 && y >= 0);
    // assert(b[x][y] > 0);
    if (b[x + dx[t]][y + dy[t]]) {
        move(x + dx[t], y + dy[t], t, b, result);
    }
    b[x + dx[t]][y + dy[t]] = b[x][y];
    b[x][y] = 0;
    result.push_back({x, y, x + dx[t], y + dy[t]});
}

vector<Move> firstStep(int n, int m, vector<vector<int>> &b) {

    // write(b);

    vector<Move> result;

    for (int i = 0; i < m; ++i) {
        int xx = -1, yy = -1;
        for (int x = i; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (b[x][y]) {
                    xx = x;
                    yy = y;
                    break;
                }
            }
            if (xx != -1) {
                break;
            }
        }

        while (xx != i) {
            move(xx, yy, 2, b, result);
            --xx;
        }

        for (int y = 0; y < n; ++y) {
            if (y == yy) {
                continue;
            }
            if (b[xx][y]) {
                move(xx, y, 0, b, result);
            }
        }
    }

    // write(b);



    for (int i = 0; i < m; ++i) {
        int xx = -1, yy = -1;
        for (int y = i; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                if (b[x][y]) {
                    xx = x;
                    yy = y;
                    break;
                }
            }
            if (xx != -1) {
                break;
            }
        }

        while (yy != i) {
            move(xx, yy, 3, b, result);
            --yy;
        }

        for (int x = 0; x < n; ++x) {
            if (x == xx) {
                continue;
            }
            if (b[x][yy]) {
                move(x, yy, 1, b, result);
            }
        }
    }

    // write(b);


    return result;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        b[x][y] = i + 1;
    }

    vector<vector<int>> t(n, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        t[x][y] = i + 1;
    }
   

    vector<Move> res1 = firstStep(n, m, b);
    vector<Move> res2 = firstStep(n, m, t);


    vector<int> xs(m + 1), ys(m + 1);
    vector<int> xf(m + 1), yf(m + 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int c = b[i][j];
            if (c > 0) {
                xs[c] = i;
                ys[c] = j;
            }

            c = t[i][j];
            if (c > 0) {
                xf[c] = i;
                yf[c] = j;
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        while (xs[i] < xf[i]) {
            move(xs[i], ys[i], 0, b, res1);
            ++xs[i];
        }

        while (xs[i] > xf[i]) {
            move(xs[i], ys[i], 2, b, res1);
            --xs[i];
        }
    }

    for (int i = 1; i <= m; ++i) {
        while (ys[i] < yf[i]) {
            move(xs[i], ys[i], 1, b, res1);
            ++ys[i];
        }

        while (ys[i] > yf[i]) {
            move(xs[i], ys[i], 3, b, res1);
            --ys[i];
        }
    }

    cout << sz(res1) + sz(res2) << endl;

    for (auto el : res1) {
        cout << el.x1 + 1 << " " << el.y1 + 1 << " " << el.x2 + 1 << " " << el.y2 + 1 << endl;
    }

    reverse(all(res2));

    for (auto el : res2) {
        cout << el.x2 + 1 << " " << el.y2 + 1 << " " << el.x1 + 1 << " " << el.y1 + 1 << endl;
    }
}