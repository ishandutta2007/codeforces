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

int n;
int a[10];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++a[x];
    }
    int ans = a[4];
    a[4] = 0;
    if (a[3]) {
        ans += a[3];
        a[1] -= a[3];
        a[1] = max(0, a[1]);
        a[3] = 0;
    }
    if (a[2]) {
        ans += a[2] / 2;
        a[2] %= 2;
        if (a[2] != 0) {
            a[2] = 0;
            ++ans;
            a[1] -= 2;
            a[1] = max(0, a[1]);
        }
    }
    if (a[1]) {
        ans += a[1] / 4;
        a[1] %= 4;
        if (a[1])
            ++ans;
    }
    cout << ans << endl;
    return 0;
}