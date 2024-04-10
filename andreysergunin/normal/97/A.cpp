#include <stdio.h>
#include <iostream>
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
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

vector<string> s;
int n, m;
vector<int> used;
vector<vector<int>> board; 
vector<vector<int>> res; 
int ans = 0;
bool f = true;
vector<int> p;

void bruteForce(int x, int y, int col) {
    if (x == n) {
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         cout << board[i][j];
        //     }
        //     cout << endl;
        // }

        // for (int i = 0; i < 49; ++i)
        //     cout << p[i];
        // cout << endl << endl;

        for (int i = 0; i < 49; ++i) {
            int u = i / 7, v = i % 7;
            if (u < v)
                continue;

            if (p[i] != 1)
                return;
        }

        if (f) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j)
                    res[i][j] = board[i][j];
            }
            f = false;
        }

        ++ans;
        return;
    }

    if (s[x][y] == '.' || board[x][y] != -1) {
        ++y;
        if (y == m) {
            y = 0;
            ++x;
        }
        bruteForce(x, y, col);
        return;
    }

    for (int i = 0; i < 2 * col + 2; ++i) {
        if (used[i])
            continue;
        if ((i & 1) && !used[i - 1])
            continue;

        used[i] = 1;
        for (int p = 0; p < 2; ++p) {
            for (int q = 0; q < 2; ++q) {
                board[x + p][y + q] = i / 2;
            }
        }

        for (int i = x; i < x + 2; ++i) {
            for (int j = y; j < y + 2; ++j) {
                if (0 < i && s[i][j] == s[i - 1][j] && board[i - 1][j] != -1) {
                    int u = board[i][j];
                    int v = board[i - 1][j];
                    if (u < v)
                        swap(u, v);
                    ++p[7 * u + v];
                }

                if (0 < j && s[i][j] == s[i][j - 1] && board[i][j - 1] != -1) {
                    int u = board[i][j];
                    int v = board[i][j - 1];
                    if (u < v)
                        swap(u, v);
                    ++p[7 * u + v];
                }

                if (i == x && j == y + 1 && j + 1 < m && s[i][j] == s[i][j + 1] && board[i][j + 1] != -1) {
                    int u = board[i][j];
                    int v = board[i][j + 1];
                    if (u < v)
                        swap(u, v);
                    ++p[7 * u + v];
                }

            }
        }

        if (y + 1 < m) 
            bruteForce(x, y + 1, col + (i == 2 * col ? 1 : 0));
        else
            bruteForce(x + 1, 0, col + (i == 2 * col ? 1 : 0));


        for (int i = x; i < x + 2; ++i) {
            for (int j = y; j < y + 2; ++j) {
                if (0 < i && s[i][j] == s[i - 1][j] && board[i - 1][j] != -1) {
                    int u = board[i][j];
                    int v = board[i - 1][j];
                    if (u < v)
                        swap(u, v);
                    --p[7 * u + v];
                }

                if (0 < j && s[i][j] == s[i][j - 1] && board[i][j - 1] != -1) {
                    int u = board[i][j];
                    int v = board[i][j - 1];
                    if (u < v)
                        swap(u, v);
                    --p[7 * u + v];
                }

                if (i == x && j == y + 1 && j + 1 < m && s[i][j] == s[i][j + 1] && board[i][j + 1] != -1) {
                    int u = board[i][j];
                    int v = board[i][j + 1];
                    if (u < v)
                        swap(u, v);
                    --p[7 * u + v];
                }

            }
        }

        used[i] = 0;
    }

    for (int p = 0; p < 2; ++p) {
        for (int q = 0; q < 2; ++q) {
            board[x + p][y + q] = -1;
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    cin >> n >> m;
    s.resize(n);
    board.resize(n, vector<int>(m, -1));
    res.resize(n, vector<int>(m, -1));

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    p.resize(49);
    used.resize(14);

    bruteForce(0, 0, 0);

    cout << ans * 7 * 6 * 5 * 4 * 3 * 2 << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << (res[i][j] == - 1 ? '.' : (char)(res[i][j] + '0'));
        cout << endl;
    }

    return 0;
}