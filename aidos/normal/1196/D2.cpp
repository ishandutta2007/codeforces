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
const int maxn = (int)2e5 + 10; //maximum + 10
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
int n, k;
int cnt[3][3];
string s;
int get_id(char c) {
	if(c == 'R') return 0;
	if(c == 'G') return 1;
	if(c == 'B') return 2;
	return -1;
}
void solve(){
	cin >> n >> k >> s;
	memset(cnt, 0, sizeof cnt);
	int ans = inf;
	for(int i = 0; i < n; i++) {
		cnt[get_id(s[i])][i % 3]++;
		if(i >= k) cnt[get_id(s[i-k])][(i-k) % 3]--;
		for(int st = 0; st < 3; st++) {
			int cur = cnt[0][st] + cnt[1][(st + 1) % 3] + cnt[2][(st+2) % 3];
			ans = min(ans, k - cur);
		}
	}
	cout << ans << "\n";
}
int main () {

	int t = 1;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		//printf("Case #%d: ", i);
		solve();
	}
    return 0;
}