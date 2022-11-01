#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int N = 100 * 1000 + 5;
const int SQ = 317;

bool cmp(pair <vector <int> , int> &p1, pair <vector <int> , int> &p2) {
	return p1.first.size() > p2.first.size();
}

int a[N];
int d[N];
pair <vector <int> , int> v[N];
int b[SQ + 5][N];
int itr[SQ + 5][N];
long long c[N];
long long s[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) {
			int y;
			cin >> y;
			v[i].first.push_back(y);
		}
		v[i].second = i;
	}
	sort(v + 1, v + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		d[v[i].second] = i;
	}
//	for (int i = 1; i <= m; i++) {
//		cout << i << " " << d[i] << endl;
//	}
	int sq = min(SQ, m);
	for (int i = 1; i <= sq; i++) {
		for (auto x : v[i].first) {
			b[i][x]++;
		}
	}
	for (int i = 1; i <= sq; i++) {
		for (int j = 1; j <= m; j++) {
			for (auto x : v[j].first) {
				itr[i][j] += b[i][x];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (auto x : v[i].first) {
			s[i] += a[x];
		}
	}
	for (int ii = 0; ii < q; ii++) {
		char qt;
		cin >> qt;
		int x;
		cin >> x;
		x = d[x];
		if (qt == '+') {
			int y;
			cin >> y;
			for (int i = 1; i <= sq; i++) {
				s[i] += 1ll * y * itr[i][x];
			}
			c[x] += y;
			if (x > sq) {
				for (auto u : v[x].first) {
					a[u] += y; 
				}
			}
		}
		else {
			if (x <= sq) {
				cout << s[x] << '\n';
			}
			else {
				long long ans = 0;
				for (auto u : v[x].first) {
					ans += a[u];
				}
				for (int i = 1; i <= sq; i++) {
					ans += 1ll * c[i] * itr[i][x];
				}
				cout << ans << '\n';
			}
		}
	}
	return 0;
}