// nlog^2 + mlog. commmme on
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 1e5 + 10;
const ll inf = 1e9 + 10;

ll a[maxn];

ll check(int n, ll x){
	ll ret = 0;
	ordered_set<pair<ll, int> > s;
	for (int i = 1; i <= n; i++){
		s.insert({a[i - 1], i});
		ret += s.order_of_key({a[i] - x, n + 1});
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	ll k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i - 1];
	}
	ll lo = -inf * n, hi = inf * n;
	while (hi - lo > 1){
		ll mid = (lo + hi) >> 1;
		if (check(n, mid) >= k)
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << endl;
}