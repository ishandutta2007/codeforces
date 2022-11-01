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

int64 n, m, ans;
pair <int64, int64> cur;
int k;
int64 k1, k2;

bool check(int64 t) {
    if (((cur.first + t * k1) > n) || ((cur.first + t * k1) <= 0))
        return false;
    if (((cur.sec + t * k2) > m) || ((cur.sec + t * k2) <= 0))
        return false;
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    cin >> cur.fir >> cur.sec;
    cin >> k;

    for (int z = 0; z < k; ++z) {
        cin >> k1 >> k2;
        int64 l = 0;
        int64 r = 2000000000;
        while (r - l > 2) {
            int64 m = (l + r) / int64(2);
            if (check(m))
                l = m;
            else r = m - 1;
        }
        for (int64 i = r; i >= l; --i)
            if (check(i)) {
                ans += i;
                cur.first += i * k1;
                cur.second += i * k2;
                break;
            }
    }
    cout << ans << endl;
    return 0;
}