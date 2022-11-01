#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
typedef long long int64;
typedef long double ld;
const ld eps = 1e-09;
const int inf = 1000000000;

int a[20000];
int64 f[20000];


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    f[0] = f[1] = 1;
    for (int i = 2; i <= 1000; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % inf;

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int d, e;
            scanf("%d %d", &d, &e);
            a[d] = e;
        }
        else {
            int l, r;
            scanf("%d %d", &l, &r);
            int64 sum = 0;
            for (int x = 0; x <= r - l; ++x) {
                sum = (sum + f[x] * int64(a[l + x])) % inf;
            }
            cout << sum << endl;
        }
    }
    return 0;
}