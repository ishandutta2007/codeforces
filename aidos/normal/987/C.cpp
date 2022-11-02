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
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp> //  . 
#include <ext/pb_ds/tree_policy.hpp> //   tree_order_statistics_node_update

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

const int inf = (1 << 29) - 1;
const int maxn = (int)5e4 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace __gnu_pbds;
using namespace std;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int n;
int s[maxn];
int dp[maxn][3];
int c[maxn];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < n; i++)
		cin >> c[i];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++)
			dp[i][j] = inf;
	}
	for(int i = 0; i < n; i++) {
		dp[i][0] = c[i];
		for(int j = 0; j < i; j++) {
			if(s[i] > s[j]) {
				for(int k = 1; k < 3; k++) {
					dp[i][k] = min(dp[j][k-1] + c[i], dp[i][k]);
				}
			}
		}
	}
	int ans = inf;
	for(int i = 0; i<n; i++) ans = min(ans, dp[i][2]);
	if(ans == inf) ans = -1;
	cout << ans << "\n";
}
int main () {

	int t = 1;
	//scanf("%d", &t);
	for(int i=1; i<=t; i++){
		//printf("Case #%d: ", i);
		solve();
	}
    return 0;
}