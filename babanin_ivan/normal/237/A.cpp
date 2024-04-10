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
    int n;
    pair <int, int> last = mp(-inf, -inf);
    int res = 1;
    int cur = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        pair <int, int> x;
        scanf("%d %d", &x.first, &x.second);
        if (x == last) {
            ++cur;
            res = max(res, cur);
        }
        else {
            cur = 1;
            last = x;
        }
    }
    cout << res << endl;
    return 0;
}