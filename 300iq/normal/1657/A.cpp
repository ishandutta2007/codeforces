#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef ONPC
mt19937 rnd(228);
#else
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    auto good = [&] (int z) {
        int t = sqrt(z);
        while (t * t < z) t++;
        return t * t == z;
    };
    while (t--) {
        int x, y;
        cin >> x >> y;
        int ans = -1;
        if (x == 0 && y == 0) {
            ans = 0;
        } else if (good(x * x + y * y)) {
            ans = 1;
        } else {
            ans = 2;
        }
        cout << ans << '\n';
    }
}