#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int n, m;
int a[20][20];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            scanf(" %c ", &c);
            if (c == 'S') {
                a[i][j] = -1;
            }
            else a[i][j] = 1;
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        bool f = true;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == -1)
                f = false;
            sum += a[i][j];
        }
        if (f) {
            res += sum;
            for (int j = 0; j < m; ++j)
                a[i][j] = 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        int sum = 0;
        bool f = true;
        for (int j = 0; j < n; ++j) {
            if (a[j][i] == -1)
                f = false;
            sum += a[j][i];
        }
        if (f) {
            res += sum;
            for (int j = 0; j < n; ++j)
                a[j][i] = 0;
        }
    }
    cout << res << endl;
    return 0;
}