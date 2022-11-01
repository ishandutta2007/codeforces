#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair <long long, int>, null_type, less<pair <long long, int> >, rb_tree_tag, tree_order_statistics_node_update>


const int N = 100 * 1000 + 5;
const long long inf = 1ll * N * N * N;
int n;
long long k;

ordered_set s;
int a[N];
long long ps[N];

bool isval(long long q) {
	while (s.size()) {
		s.erase(s.begin());
	}
	long long cnt = 0;
	for (int i = 0; i <= n; i++) {
		cnt += s.order_of_key({ps[i] - q, -1});
		s.insert({ps[i], i});
	}
//	cout << "72 " << q << " " << cnt << endl;
	if (cnt < k) {
		return true;
	}
	return false;
}


int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
	}
//	for (int i = 1; i < 10; i++) {
//		cout << "71 " << i << " " << isval(i) << endl;
//	}
	long long dw = -inf, up = inf;
	while (up - dw > 1) {
		long long md = dw + up - (dw + up) / 2;
		if (isval(md)) {
			up = md;
		}
		else {
			dw = md;
		}
	}
	cout << up;
	return 0;
}