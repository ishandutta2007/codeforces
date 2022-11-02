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
int n;
int a[5500];
int calc(int l, int r){
    if(l>r) return 0;
    int x = inf;
    for(int i = l; i <= r; i++){
        x = min(x, a[i]);
    }
    if( x >= r - l + 1 ) return r - l + 1;
    int ans = x;
    for(int i = l; i<=r;i++){
        a[i] -= x;
    }
    int prev = l-1;
    for(int i = l; i<= r; i++){
        if( a[i] == 0){
            ans += calc(prev + 1, i-1);
            prev = i;
        }
    }
    ans = min(ans + calc(prev+1, r), r-l+1);
    return ans;
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << calc(0, n-1) << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}