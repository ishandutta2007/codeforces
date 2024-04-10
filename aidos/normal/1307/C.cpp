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

string s;
ll ans[26][26];
ll cnt[26];
void solve(){
	cin >> s;
	for(const char &c: s) {
		for(int j = 0; j < 26; j++) {
			ans[j][c-'a'] += cnt[j];
		}
		cnt[c-'a']++;
	}
	ll x = 0;
	for(int i = 0; i < 26; i++){
		x = max(x, cnt[i]);
		for(int j = 0; j < 26; j++){
			x = max(ans[i][j], x);
		}
	}
	cout << x << "\n";

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