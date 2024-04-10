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
void solve(){
	ll n;
	cin >> n;
	vector<int> a;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(a.size() == 0) a.pb(x);
		else if(a.back() * 1ll * x < 0) {
			a.pb(x);
		}
		else if(a.back() <= x) {
			a.pop_back();
			a.pb(x);
		}else {

		}
	}
	ll cur = 0;
	for(int i = 0; i < a.size(); i++) cur += a[i];
	cout << cur << "\n";
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