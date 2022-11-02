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
int s;
int a[maxn];
void solve(){
	cin >> n >> s;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int cnt = 0;
	vector<int> ans;
	for(int i = 0; i < n; i++) {
		if(a[i] % 2 == 1) cnt++;
		else cnt--;
		if(cnt == 0 && i + 1 < n) ans.pb(abs(a[i] - a[i+1]));
	}
	if(cnt != 0) {
		cout << 0 << "\n";
		return;
	}
	sort(all(ans));
	int cur = 0;
	for(int i = 0; i < ans.size(); i++) {
		if(s >= ans[i]) {
			s -= ans[i];
			cur++;
		}
	}
	cout << cur << "\n";
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