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
ld a, d;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> a >> d;
    ld last = -1;

    for (int i = 0; i < n; ++i) {
        int t, v;
        scanf("%d %d", &t, &v);
        ld t1 = ld(v) / ld(a);
        if ((ld(a) * ld(t1) * ld(t1) / ld(2)) <= d) {
            t1 += (d - (ld(a) * ld(t1) * ld(t1) / ld(2))) / v;
        }
        else t1 = sqrt((ld(2) * ld(d)) / ld(a));
        t1 += ld(t);
        if (t1 < last)
            t1 = last;
        cout.precision(10);
        cout << fixed << t1 << endl;
        last = t1;
    }
    return 0;
}