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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1 << 30);
const int maxn = 1 << 18;

using namespace std;

int n, k;
int a[2100];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n >> k;
    int maxi = 0;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        a[x]++;
        maxi = max(x, maxi);
    }
    int m = n;
    int ans = 0;
    for(int i = 2;i <= 2000; i++){
        int x = 2 * (( m + k - 1)/k);
        if( x > 0 ) x--;
        ans +=x;
        m -= a[i];
    }
    ans += maxi - 1;
    cout << ans << endl;

    



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}