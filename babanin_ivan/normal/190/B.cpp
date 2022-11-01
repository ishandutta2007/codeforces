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

pair <ld, ld> a[2];
ld r[2];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    for (int i = 0; i < 2; ++i)
        cin >> a[i].first >> a[i].sec >> r[i];
    ld d = sqrt((a[0].first - a[1].first) * (a[0].first - a[1].first) + (a[0].second - a[1].second) * (a[0].second - a[1].second));
    cout.precision(10);
    cout << fixed;
    if (d >= r[0] + r[1]) {
        cout << (d - (r[0] + r[1])) / 2.0 << endl;
        return 0;
    }
    if (d >= r[0] && d >= r[1]) {
        cout << 0 << endl;
        return 0;
    }
    if (r[0] < r[1]) {
        swap(r[0], r[1]);
        swap(a[0], a[1]);
    }
    if (d + r[1] >= r[0]) {
        cout << 0 << endl;
    }
    else {
        cout << (r[0] - (d + r[1])) / 2.0 << endl;
    }
    return 0;
}