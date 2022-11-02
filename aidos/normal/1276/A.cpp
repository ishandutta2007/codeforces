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
int n, m;
string s;
int wasa[maxn];
int wasb[maxn];
void solve(){
	cin >> s;
	for(int i = 0; i + 2 < s.size(); i++) {
		if(s[i] == 'o' && s[i + 1] == 'n' && s[i+2] == 'e') {
			wasa[i] = 1;
		}
		if(s[i] == 't' && s[i + 1] == 'w' && s[i+2] == 'o') {
			wasb[i] = 1;
		}
	}
	vector<int> ans;
	for(int i = 0; i < s.size(); i++) {
		if(wasa[i]) {
			ans.pb(i+2);
		}
		if(wasb[i]) {
			if(wasa[i+2]) {
				ans.pb(i+3);
				i += 3;
			}
			else {
				ans.pb(i+2);
			}
		}
	}
	cout << ans.size() << "\n";
	for(const int &pos: ans) cout << pos << " ";
	cout << "\n";
	for(int i = 0; i < s.size(); i++) wasa[i] = wasb[i] = 0;
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