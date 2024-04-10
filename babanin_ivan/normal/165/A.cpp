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
pair <int, int> a[1000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d %d", &a[i].first, &a[i].second);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        for (int j = 0; j < n; ++j)
            if ((a[i].first == a[j].first) && (a[i].second < a[j].second)) {
                ++k;
                break;
            }
        for (int j = 0; j < n; ++j)
            if ((a[i].first == a[j].first) && (a[i].second > a[j].second)) {
                ++k;
                break;
            }
        for (int j = 0; j < n; ++j)
            if ((a[i].sec == a[j].sec) && (a[i].fir < a[j].fir)) {
                ++k;
                break;
            }
        for (int j = 0; j < n; ++j)
            if ((a[i].sec == a[j].sec) && (a[i].fir > a[j].fir)) {
                ++k;
                break;
            }
        if (k == 4)
            ++res;
    }
    cout << res << endl;
    return 0;
}