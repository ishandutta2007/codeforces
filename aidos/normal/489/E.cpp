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
#include <bitset>

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
const int mod = (int) 1e9 + 7;
using namespace std;
double dp[1111];
double d[1111][1111];
int n;
double l;
double x[1111], b[1111];
int prv[1111];
bool ok(double x) {
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		dp[i] = inf;
		for(int j = 0; j < i; j++){
			double c = d[i][j] - x * b[i] + dp[j];
			if(c < dp[i]){
				dp[i] = c;
				prv[i] = j;
			}
		}
	}
	return dp[n] <= 0.0;
}

void solve(){
	cin >> n >> l;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> b[i];
	}
	for(int i = 0;i <= n; i++) {
		for(int j = 0;  j <= n; j++){
			d[i][j] = sqrt(abs(abs(x[j] - x[i]) - l));
		}
	}
	double l = 0, r = 1e4;
	for(int iter = 0; iter < 100; iter++){
		double mid = (l + r)/2.0;
		if(ok(mid)) {
			r = mid;
		}else l = mid;
	}
	ok(r);
	vector<int> ans;
	while(n>0){
		ans.pb(n);
		n = prv[n];
	}
	reverse(all(ans));
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}