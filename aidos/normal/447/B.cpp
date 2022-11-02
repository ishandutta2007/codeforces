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
#include <ctime>

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
const int maxn = (int) 1e3 + 10;

using namespace std;


char c[maxn];
int maxi = 0;
int t[maxn];
int n, k;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%s\n", &c);
    n = strlen(c);
    scanf("%d\n", &k);
    for(int i = 0; i < 26; i++) {
        scanf("%d ", &t[i]);
        maxi = max(maxi, t[i]);
    }
    ll ans = 0;
    for(int i = 0; i< n; i++){
        ans += (i + 1) * 1ll * t[c[i]-'a'];
    }
    for(int i = 1; i <= k; i++){
        ans += (i + n)  *1ll * maxi;
    }
    cout << ans << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}