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

int n, x;
int a[10000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int ans = 0;
    while (true) {
        if (a[(int(n + 1) / 2) - 1] == x)
            break;
        ++n;
        a[n - 1] = x;
        ++ans;
        int i = n - 1;
        while ((i > 0) && (a[i] < a[i - 1])) {
            swap(a[i], a[i - 1]);
            --i;
        }
    }
    cout << ans << endl;
    return 0;
}