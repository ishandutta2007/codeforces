#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int d[222][222][222];

int main() {
    init_cin
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cr = 0, cg = 0, cb = 0;
    for (char c : s) {
        if (c == 'R') {
            cr++;
        }
        if (c == 'G') {
            cg++;
        }
        if (c == 'B') {
            cb++;
        }
    }
    d[cr][cg][cb] = 1;
    for (int sum = n; sum >= 0; sum--) {
        for (int i1 = sum; i1 >= 0; i1--) {
            for (int i2 = sum - i1; i2 >= 0; i2--) {
                int i = i1;
                int j = i2;
                int k = sum - i1 - i2;
                if (k < 0 || i + k + j > sum || d[i][j][k] == 0) {
                    continue;
                }
                if (i >= 2) {
                    d[i - 1][j][k] = 1;
                }
                if (j >= 2) {
                    d[i][j - 1][k] = 1;
                }
                if (k >= 2) {
                    d[i][j][k - 1] = 1;
                }
                if (i && j) {
                    d[i - 1][j - 1][k + 1] = 1;
                }
                if (i && k) {
                    d[i - 1][j + 1][k - 1] = 1;
                }
                if (j && k) {
                    d[i + 1][j - 1][k - 1] = 1;
                }
            }
        }
    }
    if (d[0][0][1]) {
        cout << "B";
    }
    if (d[0][1][0]) {
        cout << "G";
    }
    if (d[1][0][0]) {
        cout << "R";
    }

    return 0;
}