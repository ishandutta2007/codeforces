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

#define MAXN (int) (1e5) + 10
using namespace std;

int n;
int x[MAXN];
ll dp[MAXN];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    sort(x, x + n);
    ll prev=0, ans = 0;
    for(int i = 0; i < n;){
        int j = i;
        while( j < n && x[i] == x[j]) j++;

        if( i > 0 && x[i] == x[i-1] + 1){
            dp[j-1] = prev;
            prev = dp[i-1] + ( j - i ) * 1ll * x[i];
            dp[j-1] = max(dp[i-1], dp[j-1]);
        }
        else {
            dp[j-1] = prev;
            if( i > 0){
                prev = max(prev + x[i] * 1ll * ( j - i), dp[i-1]+x[i] * 1ll * ( j - i));
                dp[j-1] = max(dp[j-1], dp[i-1]);
            }
            else {
                prev = x[i] * 1ll * ( j - i);
            }
        }
       // cout << dp[j-1] << " " << prev << endl;
        ans = max(ans, prev);
        i = j;
    } 
    cout << ans << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}