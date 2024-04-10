#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

int n, a, b, T;
char c[1000100]; 
int dp[1000100];
int mm;
int ok(int x){
	if(T < x)  return 0;
	for(int i= 0; i < x; i++){
		int dis = min(2 * (x - i - 1) + i, 2 * i + (x - i - 1));
		ll xx = dis * a + dp[i+mm] - dp[i + mm - x] + x;
		if(xx <= T) return 1;
	}
	return 0;

}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d %d %d", &n, &a, &b, &T);
    int l = 1, r = n, ans = 0;
    scanf("%s", c);
    for(int i = 0; i < n; i++){
    	c[i+n] = c[i];
    }
    mm  = n;
    n *= 2;
    int sum = 0;
    for(int i = 0; i < n; i++){
    	sum += (c[i] == 'w') * b;
    	dp[i] = sum;
    }
    while(l <= r){
    	int mid = (l + r)>>1;
    	if(ok(mid)) {
    		l = mid+1;
    		ans = mid;
    	}else r = mid-1;
    }
    cout << ans << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}