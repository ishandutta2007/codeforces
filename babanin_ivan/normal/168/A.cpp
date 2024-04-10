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

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int64 n, x, y;
    cin >> n >> x >> y;
    ld n1, x1, y1;
    n1 = ld(n);
    x1 = ld(x);
    y1 = ld(y);
    ld k = (n1 / 100.0) * y1 - x1;
    if (k <= 0) {
        cout << 0 << endl;
        return 0;
    }
    int res = int(k);
    if (k > res)
        ++res;
    cout << res << endl;
    return 0;
}