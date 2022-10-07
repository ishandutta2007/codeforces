#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = -1;
const int INF = 1e9;
const int T = 2e7;

int n, m, k;
long long ans = 0;

inline void solve(int n, int m) {
    for (int x = 1; x <= min(n, T); x++) {
        int t = n / x - 1;
        if (t > k) t = k;
        int y = m / (k - t + 1);
        ans = max(ans, x * 1ll * y);
        //if (x % 100000 == 1 || x < 10) 
            //cerr << "x y t res: " << x << " " << y << " " << t << " " << x * 1ll * y << " m k   "  << m << " " << k << endl;
        //cerr << t
    }
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int x, y;
    scanf("%d%d%d", &n, &m, &k);
    if (n - 1 + m - 1 < k) {
        printf("-1\n");
        return 0;
    }
    if (k < T) {
    //if (false) {
        for (int i = 0; i <= k; i++) {
            x = n / (i + 1);
            y = m / (k - i + 1);
            ans = max(ans, x * 1ll * y);
            //cerr << "k: " << k << " " << x * 1ll * y << endl;
        }
    }
    else {
        solve(n, m);
        solve(m, n);
    }
    printf("%lld\n", ans);
    return 0;
}