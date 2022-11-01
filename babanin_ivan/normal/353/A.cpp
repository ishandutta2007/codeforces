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

pair <int, int> a[200];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    scanf("%d ", &n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    int sum1, sum2;
    sum1 = sum2 = 0;
    for (int i = 0; i < n; ++i) {
        sum1 += a[i].first;
        sum2 += a[i].second;
    }
    if ((sum1 % 2 == 0) && (sum2 % 2 == 0)) {
        cout << 0 << endl;
        return 0;
    }
    if ((sum1 % 2) != (sum2 % 2)) {
        cout << -1 << endl;
        return 0;
    }
    bool f = false;
    for (int i = 0; i < n; ++i)
        if ((a[i].first % 2) != (a[i].second % 2))
            f = true;
    if (f) {
        cout << 1 << endl;
    }
    else cout << -1 << endl;
    return 0;
}