#include<bits/stdc++.h>
using namespace std;
struct info {
	int id, cnt;
}in[100005];
bool operator<(const info &a, const info &b) {
	return a.cnt < b.cnt;
}
vector<int> v[100005];
int ans[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;
		for (int i = 1; i <= n + 1; i++) in[i].id = i, in[i].cnt = 0, v[i].clear();
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			v[a].push_back(i), ++in[a].cnt;
		}
		int emp = 0;
		for (int i = 1; i <= n + 1; i++)
			if (!in[i].cnt) {
				emp = i;
				break;
			}
		for (int i = 1; i <= n; i++) ans[i] = emp;
		sort(in + 1, in + n + 2);
		int p = n + 1;
		for (int i = 1; i <= x; i++) {
			int id = in[p].id;
			ans[*(v[id].end()-1)] = id, v[id].pop_back(), --in[p].cnt;
			if (in[p-1].cnt <= in[p].cnt) p = n + 1;
			else --p;
		}
		sort(in + 1, in + n + 2);
		if ((n - x - in[n+1].cnt) * 2 < y - x) {
			puts("NO");
			continue;
		}
		puts("YES");
		p = n;
		int q = in[p].cnt - 1;
		for (int i = n + 1; i >= 1 && y > x; i--) {
			int id = in[i].id;
			for (int j = 0; j < v[id].size() && y > x; j++) {
				if (p == i) break;
				ans[v[in[p].id][q]] = id, --y;
				--q;
				while (q < 0) {
					--p;
					if (!p) p = n + 1;
					q = in[p].cnt-1;
				}
			}
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
		cout << endl;
	}
}