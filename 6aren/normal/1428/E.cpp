#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;

int n, k;
int a[N];
int ng[N];


int calc(int u, int v) {
	int foo = u / v;
	int cnt = u % v;
	return (cnt * (foo + 1) * (foo + 1) + (v - cnt) * foo * foo);
}



signed main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ng[i] = 1;
	}

	sort(a + 1, a + n + 1);

	set<int> s;
	s.insert(n);

	int u = k - n;

	while (u--) {
		int id = 0;
		int mx = 0;
		for (int e : s) {
			// cout << e << endl;
			int foo = calc(a[e], ng[e]) - calc(a[e], ng[e] + 1);
			// cout << a[e] << ' ' << ng[e] << ' ' << foo << endl;
			if (foo > mx) {
				mx = foo;
				id = e;
			}
		}
		ng[id]++;
		s.erase(id);
		if (id != 1) 
			s.insert(id - 1);
		s.insert(n);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) 
		ans += calc(a[i], ng[i]);

	cout << ans << endl;

	return 0;
}