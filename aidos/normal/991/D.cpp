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

string s;
string t;
int dp[maxn][4];
void solve(){
	cin >> s >> t;
	n = s.size();
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < 4; j++)
			dp[i][j] = -inf;
	}
	dp[0][3] = 0;
	for(int i = 1; i <= n; i++) {
		int cur = 0;
		if(s[i-1] == 'X') cur += 1;
		if(t[i-1] == 'X') cur += 2;
		for(int m1 = 0; m1 < 4; m1++) {
			if((m1&cur) != cur)continue;
			for(int m2 = 0; m2 < 4; m2++) {
				if(2-__builtin_popcount(m1^cur) + __builtin_popcount(m2) != 1) {
					dp[i][m1] = max(dp[i-1][m2], dp[i][m1]);
				}else {
					dp[i][m1] = max(dp[i-1][m2]+1, dp[i][m1]);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j < 4; j++)
			ans = max(ans, dp[i][j]);
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