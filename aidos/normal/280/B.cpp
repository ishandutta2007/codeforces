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

int a[maxn];
int n;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    int x = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int ans=0;
    for(int t = 30; t >= 0; t--){
    int k = (1 << t);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if( a[i] & k ) cnt++;
    }
    if( cnt == 0 || cnt==n) continue;
    for(int i = 0; i < n; i++){
        if( a[i] & k){
            int maxi = 0;
                for(int j = i+1;j < n; j++){
                    if( a[j] & k ) break;
                        maxi = max(maxi, a[j]);
                        ans = max(a[i] ^ maxi, ans);
                    }
                maxi = 0;
                for(int j = i-1; j>=0; j--){
                    if( a[j] & k) break;
                    maxi = max(maxi, a[j]);
                    ans = max(a[i]^maxi, ans);
                }
        }
    }
    break;
    }
    
    cout << ans << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}