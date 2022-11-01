#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

const int N = 200 * 1000 + 5;
int n;

int a[N];
int b[N];
long long inv[N];
long long ans[N];
long long seg[N * 4];
ordered_set s1;
ordered_set s2;
void update(int p, int id = 1, int s = 1, int e = n + 1) {
	if (e <= p || p < s) {
		return;
	}
	if (e - s == 1) {
		seg[id] = p;
		return;
	}
	int md = (s + e) / 2;
	update(p, id * 2, s, md);
	update(p, id * 2 + 1, md, e);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
long long get(int l, int r, int id = 1, int s = 1, int e = n + 1) {
	if (e <= l || r <= s) {
		return 0;
	}
	if (l <= s && e <= r) {
		return seg[id];
	}
	int md = (s + e) / 2;
	long long ans = 0;
	ans += get(l, r, id * 2, s, md);
	ans += get(l, r, id * 2 + 1, md, e);
	return ans;
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		int x = i - s1.order_of_key(b[i]) - 1;
		inv[i] += x;
		s1.insert(b[i]);
		update(b[i]);
		int y = *s1.find_by_order(i / 2);
		long long t1 = get(1, y), t2 = get(y, n + 1);
		int f = i / 2, c = i - i / 2;
		long long s = t2 - 1ll * c * y;
		s += 1ll * f * y - t1;
	//	cout << "73 " << y << " " << t1 << " " << t2 << endl;
		if (i % 2 == 1) {
			s -= 1ll * f * (f + 1);
		}
		else {
			s -= 1ll * f * (f + 1);
			s += f;
		}
		ans[i] = s;
	}
	for (int i = 1; i <= n; i++) {
		inv[i] = inv[i - 1] + inv[i];
		cout << ans[i] + inv[i] << " ";
	}
	return 0;
}