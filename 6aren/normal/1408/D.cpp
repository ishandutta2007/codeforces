#include<bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define x first
#define y second

const int N = 2005;

ii r[N], s[N];
int n, m;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> r[i].x >> r[i].y;
	}

	for (int i = 1; i <= m; i++) {
		cin >> s[i].x >> s[i].y;
		s[i].x++;
		s[i].y++;
	}

	vector<ii> a;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int u = s[j].x - r[i].x;
			int v = s[j].y - r[i].y;
			if (u > 0 && v > 0) a.push_back(ii(u, v)); 
		}
	}

	sort(a.rbegin(), a.rend());


	int ans = 1e9;

	int mx = 0;
	for (ii e : a) {
		if (e.y > mx) {
			ans = min(ans, e.x + mx);
			mx = e.y;
		} 
	}
	ans = min(ans, mx);

	cout << ans << '\n';


	return 0;
}