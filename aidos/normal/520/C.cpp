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
int mod = 1000000007;
int n;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    string s;
    cin >> n >> s;
    sort(all(s));
    int maxi = 0;
    int cnt = 0;
    for(int i = 0; i < n; ){
    	int j = i;
    	while( i < n && s[i] == s[j]) i++;
    	if( i-j > maxi){
    		maxi = i-j;
    		cnt = 1;
    	}
    	else if( i-j == maxi){
    		cnt++;
    	}
    }
    int ans = 1;
    while( n > 0){
    	if(n & 1) {
    		ans = ans * 1ll * cnt % mod;
    	}
    	cnt = (cnt * 1ll * cnt) % mod;
    	n/=2;
    }
    cout << ans << endl;








    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}