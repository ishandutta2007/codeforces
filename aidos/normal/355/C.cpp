#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e5) + 10
using namespace std;

int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i-1];   
    }
    int ans = (int)(2e9);
    for(int i = 0; i <= n; i++){
        int cur = a[i] * l + (a[n] - a[i]) * r;
        if(  i > n - i ) cur += (2*i - n-1)*ql;
        if( i < n - i) cur += ( n - 2 * i - 1) * qr;
        ans = min(ans, cur);
    }
    //ans = min(ans, a[n-1] * r + n * qr);
    cout << ans << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}