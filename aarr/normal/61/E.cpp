#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair <int, int>, null_type, less<pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update>


const int N = 1000 * 1000 + 5;

int a[N];
int r[N];
int l[N];
ordered_set s1;
ordered_set s2;

int main() {
    ios :: sync_with_stdio(false);
	int n;
	cin >> n;
//	s1.insert({2, 3});
//	cout << s2.order_of_key({2, 5});
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i; i--) {
		r[i] = s2.order_of_key({a[i], n - i});
		s2.insert({a[i], n - i});
	}
	for (int i = 1; i <= n; i++) {
		l[i] = i - s1.order_of_key({a[i], i}) - 1;
		s1.insert({a[i], i});
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += 1ll * l[i] * r[i];
	}
	cout << ans << endl;
	return 0;
}