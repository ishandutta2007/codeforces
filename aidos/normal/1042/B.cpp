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
int n;
map<int, int> M;
vector<pii> v;
int ans;
void rec(int pos, int mask, int cost) {
	if(pos == v.size()) {
		if(mask == 7) {
			if(ans == -1) ans = cost;
			else ans = min(ans, cost);
		}
		return;
	}
	rec(pos + 1, mask, cost);
	rec(pos + 1, mask | v[pos].f, cost + v[pos].s);
}
void solve(){
	cin >> n;

	for(int i=0; i < n; i++) {
		string s;
		int p;
		cin >> p >> s;
		sort(all(s));
		int mask = 0;
		for(int j = 0; j < s.size(); j++)
			mask |= (1<<(s[j] - 'A'));
		if(M.count(mask) == 0) M[mask] = p;
		else M[mask] = min(M[mask], p);
	}
	for(auto x: M) {
		v.pb(x);
	}
	ans = -1;
	rec(0, 0, 0);
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