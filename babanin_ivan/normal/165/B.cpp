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

int64 n, k;

bool check(int64 x) {
    int64 sum = x;
    int64 curk = k;
    while (x >= curk) {
        sum += x / curk;
        if (sum >= n)
            return true;
        curk *= k;
    }
    if (sum >= n)
        return true;
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  
    cin >> n >> k;
    int64 l = 0;
    int64 r = inf;
    while (r - l > 2) {
        int64 m = (l + r) / 2LL;
        if (check(m))
            r = m;
        else l = m;
    }
    for (int64 i = l; i <= r; ++i)
        if (check(i)) {
            cout << i << endl;
            return 0;
        }
    return 0;
}