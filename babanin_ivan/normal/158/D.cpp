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
int a[40000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int ans = -inf;
    for (int j = 1; j < n; ++j)
        if (n % j == 0) {
            if (n / j < 3)
                continue;
            for (int i = 0; i < j; ++i) {
                int sum = 0;
                int cur = i;
                for (int x = 0; x < n / j; ++x) {
                    sum += a[cur];
                    cur = (cur + j) % n;
                }
                ans = max(ans, sum);
            }
        }
    cout << ans << endl;
    return 0;
}