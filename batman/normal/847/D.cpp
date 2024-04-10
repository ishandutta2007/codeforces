#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 17;
int n, a[maxn], t, ans;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> s;
map<int, int> cnt;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> t;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s.insert({i - a[i], cnt[ i - a[i] ]++});
	}
	int ptr = n;
	for(int st = max(0, t - n - 1); st < t; st++){
		while(ptr >= t - st){
			s.erase({ptr - a[ptr], --cnt[ ptr - a[ptr] ]});
			ptr--;
		}
		ans = max<int>(ans, s.size() - s.order_of_key({-st, -1}));
	}
	cout << ans << '\n';
	return 0;
}