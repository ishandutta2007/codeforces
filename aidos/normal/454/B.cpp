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
const int maxn = (int) 1e5 + 10;

using namespace std;

int n;
int a[maxn];
int dp[maxn];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[n + 1] = inf;
    for(int i = n; i > 0; i--){
        dp[i] = dp[i+1] + (a[i] <= a[i+1]);
    }
    if( dp[1] == n){
        cout << 0 << endl;
        return 0;
    }
    if( a[n] > a[1]){
        cout << -1 << endl;
        return 0;
    }
    for(int i = n; i>1; i--){
        
        int x = dp[i]+1;
        int y = dp[1] - dp[i] - (a[i-1] <= a[i]);
//        cout << x << " " << y << endl;
        if( x + y == n){
            cout << n - i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}