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

#define MAXN (int) (1e7)
using namespace std;

int n, k, x;
    
int a[111];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k  >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans=0;
    for(int i = 1; i < n; ){
        if( a[i] != x){
            i++;
            continue;
        }
        if( a[i] != a[i-1]) {
            i++;
            continue;
        }
        int l = i - 2;
        int r = i + 1;
        while(l >= 0 && r < n && a[l] == a[r]){
            int z = a[l];
            int col = 0;
            while( z == a[l] ) {
                col++;
                l--;
            }
            while( z == a[r]) {
                r++;
                col++;
            }
            if( col == 2){
                l++;
                r--;
                break;
            }
        }
        ans = max(ans, r - l - 1);
        i ++;
    }
    cout << ans << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}