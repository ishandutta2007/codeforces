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
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
int n;
int a[100010];
int cnt[100010];
bool check(int x){
    int k = 0;
    while( k < n){
        int z = k+1;
        while( z < n && a[z] > a[z-1] ) {
            z++;
        }
        cnt[k] = z;
        k = z;
    }
    int t = 0;
    int xx = -1;
    int zz = -1;
    while( t < n){
        if( cnt[t]-t >= x ){
            return 1;
        }

        if( t ){
            int y = t - 1;
            if( cnt[t] - y >= x) return 1;
        }
        if( cnt[t] == n) return 0;
        int z = cnt[t];
        if( cnt[z] == n){
            if( cnt[z] - z == 1) {if(cnt[z] - t >= x ) return 1;
            else 
                return 0;
            }
            int y = z + 1;
            if( a[y] > a[z-1] + 1 || z - t == 1 || a[z] > a[z-2] +1) {
                if( cnt[z] - t >= x ) return 1;
                return 0;
            }
        }
        else {
            if(cnt[z]-z == 1){
                int y =z + 1;
                if( a[z + 1] > a[z-1] + 1 && cnt[y] - t >= x){
                    return 1;
                }
            }
            else {
                if( (a[z + 1] > a[z-1] + 1 || (z - t > 1 &&a[z] > a[z-2] +1 ) || z-t == 1 )&& cnt[z] - t >= x){
                    return 1;
                }
            }
            
        }
        if( cnt[t] - t + 1 == x ) return 1;
        zz = xx;
        xx = t;
        t = cnt[t];
    }
    return 0;
}
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i  = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 2, r = n, ans = 1;
    while( l<=r){
        int mid = (l + r) >> 1;
        if(check( mid ) ){
            ans = mid;
            l = mid+1;
        }
        else {
            r= mid-1;
        }
    }
    cout << ans << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}