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
int a[1111];



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i];  
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
    	int l = i-1;
    	int r = i+1;
    	while(r < n && a[r] <= a[r-1]) r++;
    	while(l >= 0 && a[l] <= a[l+1]) l--;
    	ans = max(r - l - 1, ans);
    }
    cout << ans << endl;


    



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}