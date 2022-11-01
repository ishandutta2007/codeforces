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
int a[200][200];
int b[200];
int c[200];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            char c;
            scanf(" %c ", &c);
            a[i][j] = c - '0';
        }
    for (int i = 0; i < m; ++i) {
        b[i] = -1;
        for (int j = 0; j < n; ++j) {
            if (a[j][i] > b[i])
                b[i] = a[j][i], c[i] = 0;
            if (a[j][i] == b[i])
                ++c[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool f = false;
        for (int j = 0; j < m; ++j)
            if (b[j] == a[i][j])
                f = true;
        if (f)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}