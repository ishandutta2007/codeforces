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

struct Point {
    int x, y;
};

int dist(Point &a, Point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 


    int n, k;
    cin >> n >> k;

    vector<Point> a(k), b(k);

    vector<Point> to;
    vector<int> id;

    vector<vector<int>> board(4, vector<int>(n));

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            int d;
            cin >> d;
            board[i][j] = (d > 0);
            if (d != 0) {
                --d;
                if (i == 0 || i == 3) {
                    b[d].x = i;
                    b[d].y = j;
                } else {
                    a[d].x = i;
                    a[d].y = j;
                }
            }
        }
            
    }

    vector<int> used(k);

    int rem = k;

    for (int i = 0; i < k; ++i) {
        if (dist(a[i], b[i]) == 1) {
            to.push_back(b[i]);
            id.push_back(i);
            board[a[i].x][a[i].y] = 0;
            used[i] = 1;
            --rem;
        }
    }

    if (rem == 2 * n) {
        cout << -1 << endl;
        return 0;
    }

    while (rem > 0) {

        for (int i = 0; i < k; ++i) {
            if (used[i]) {
                continue;
            }

            if (a[i].x == 1) {
                if (a[i].y != 0) {
                    if (board[a[i].x][a[i].y - 1] == 0) {
                        board[a[i].x][a[i].y - 1] = 1;
                        board[a[i].x][a[i].y] = 0;
                        --a[i].y;

                        to.push_back(a[i]);
                        id.push_back(i);
                    }
                } else {
                    if (board[a[i].x + 1][a[i].y] == 0) {
                        board[a[i].x + 1][a[i].y] = 1;
                        board[a[i].x][a[i].y] = 0;
                        ++a[i].x;

                        to.push_back(a[i]);
                        id.push_back(i);
                    }
                }
            } else {
                if (a[i].y != n - 1) {
                    if (board[a[i].x][a[i].y + 1] == 0) {
                        board[a[i].x][a[i].y + 1] = 1;
                        board[a[i].x][a[i].y] = 0;
                        ++a[i].y;

                        to.push_back(a[i]);
                        id.push_back(i);
                    }
                } else {
                    if (board[a[i].x - 1][a[i].y] == 0) {
                        board[a[i].x - 1][a[i].y] = 1;
                        board[a[i].x][a[i].y] = 0;
                        --a[i].x;

                        to.push_back(a[i]);
                        id.push_back(i);
                    }
                }
            }
        }


        for (int i = 0; i < k; ++i) {
            if (dist(a[i], b[i]) == 1 && used[i] == 0) {
                to.push_back(b[i]);
                id.push_back(i);
                used[i] = 1;
                board[a[i].x][a[i].y] = 0;
                --rem;
            }
        }
    }

    cout << sz(id) << endl;
    for (int i = 0; i < sz(id); ++i) {
        cout << id[i] + 1 << " " << to[i].x + 1 << " " << to[i].y + 1 << endl;
    }

    return 0;
}