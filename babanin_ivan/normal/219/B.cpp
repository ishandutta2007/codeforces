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
#define pow botva55
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int64 pow[100];
int64 nine[100];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    pow[0] = 1;
    for (int i = 1; i < 100; ++i)
        pow[i] = pow[i - 1] * 10LL;
    nine[0] = 0;
    for (int i = 1; i < 100; ++i)
        nine[i] = nine[i - 1] * 10LL + 9LL;
    int64 p, d;
    cin >> p >> d;
    int64 bestres = p;

    for (int i = 0; i <= 18; ++i) {
        int64 l = 0;
        int64 r = nine[18 - i];
        while (r - l > 2LL) {
            int64 m = (l + r) / 2LL;
            if (m * pow[i] + nine[i] <= p)
                l = m;
            else r = m;
        }
        int64 cur = -1;
        for (int64 j = l; j <= r; ++j)
            if (j * pow[i] + nine[i] <= p)
                cur = j;
        cur = cur * pow[i] + nine[i];
        if ((cur != -1) && ((p - cur) <= d))
            bestres = cur;
    }
    cout << bestres << endl;
    return 0;
}