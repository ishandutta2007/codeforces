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

#define MAXN (int) (1e7)
using namespace std;
int n, m;
ll k;
ll check(ll x ){
    ll cnt = 0;

    int r = m, l = 1, ans = m;
    for(int i = 1; i <= n; i++){
        l = 1;
        r = ans;
        ans =0;
        while ( l <= r ){
            int mid = ( l + r ) >> 1;
            if( mid * 1ll * i <= x){
                l=mid+1;
                ans = mid;
            }
            else {
                r = mid-1;
            }
        }
        cnt += ans;
    }
    return cnt;
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n >> m >> k;
    ll l = 1, r = n*1ll*m, ans=-1;
    while( l<=r){
        ll mid = (l + r) /2;
        if( check(mid) >= k){
            r = mid-1;
            ans = mid;
        }
        else l = mid+1;
    }
    cout << ans << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}