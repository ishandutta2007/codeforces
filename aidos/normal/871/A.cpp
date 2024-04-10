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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int is_p[510];
int dp[510];
int prime(int x){
	if(x == 1) return 0;
	for(int i = 2; i < x; i++){
		if(x % i == 0) return 0;
	}
	return 1;
}

int get(int x){
	if(x % 4 == 0) return x/4;
	return -inf;
}

void solve(){
	dp[1] = -1;
	dp[2] = -1;
	dp[3] = -1;
	dp[0] = 0;
	for(int i = 2; i < 500; i++)
		is_p[i] = prime(i);
	for(int i = 4; i < 500; i++){
		dp[i] = -1;
		for(int j = 2; j <= i; j++){
			if(!is_p[j] && dp[i-j] >= 0){
				dp[i] = max(dp[i], dp[i-j] + 1);
			}
		}
	}
	int q;
	scanf("%d", &q);
	for(int i = 0, n; i < q; i++){
		scanf("%d", &n);
		if(n < 500){
			printf("%d\n", dp[n]);
		}
		else{
			int ans=-inf;
			for(int i = 2; i < 500; i++){
				if(dp[i] > 0) {
					ans = max(ans, dp[i] + get(n-i));
				}
			}
			printf("%d\n", ans);
		}
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}