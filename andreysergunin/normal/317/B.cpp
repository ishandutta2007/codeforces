#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;

const int MAXN = 100;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, t;
    cin >> n >> t;
    int a[2 * MAXN + 1][2 * MAXN + 1];
    for (int i = 0; i < 2 * MAXN + 1; i++)
        for (int j = 0; j < 2 * MAXN + 1; j++)
            a[i][j] = 0;
    a[MAXN][MAXN] = n;
    for (int k = 0; k < 5000; k++) {
        for (int i = 1; i < 2 * MAXN; i++)
            for (int j = 1; j < 2 * MAXN; j++) {
                if (a[i][j] >= 4) {
                    a[i - 1][j] += a[i][j] / 4;
                    a[i + 1][j] += a[i][j] / 4;
                    a[i][j - 1] += a[i][j] / 4;
                    a[i][j + 1] += a[i][j] / 4;
                    a[i][j] %= 4;
                }
            }
    }
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        if (abs(x) < MAXN && abs(y) < MAXN)
            cout << a[x + MAXN][y + MAXN] << endl;
        else
            cout << 0 << endl;
    }
    
}