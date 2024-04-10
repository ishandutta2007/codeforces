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

int64 gcd(int64 x, int64 y) {
    if (x % y == 0)
        return y;
    else return gcd(y, x % y);
}

int64 n;
int64 a[101000];
int64 suf[101000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int64 sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + a[i];
    }
    int64 sum2 = 0;
    for (int i = 0; i < n; ++i) {
        sum2 += suf[i + 1] - (n - i - 1) * a[i];
    }
    int64 ans1 = sum + 2 * sum2;
    int64 ans2 = n;
    int64 g = gcd(ans1, ans2);
    cout << ans1 / g << " " << ans2 / g << endl;
    return 0;
}