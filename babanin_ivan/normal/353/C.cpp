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

int a[200000];
char c[200000];
int sump[200000];
int n;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf(" %c ", &c[i]);
    for (int i = 1; i <= n; ++i)
        sump[i] = sump[i - 1] + a[i];
    int res = 0;
    int cursum = 0;
    for (int i = n; i >= 1; --i) {
        if (c[i] == '1') {
            res = max(res, cursum + sump[i - 1]);
            cursum += a[i];
        }
    }
    res = max(res, cursum);
    cout << res << endl;
    return 0;
}