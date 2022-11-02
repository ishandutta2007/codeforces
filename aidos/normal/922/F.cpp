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
#include <cassert>

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


const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n, k;
int dp[300300];
vector<int> g[300300];
void solve() {
	cin >> n >> k;
	int ans = 0;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i*2; j <= n; j+=i) {
			g[j].pb(i);
			++ans;
		}
		mx = max(mx, (int)g[i].size());
	}
	//cout << mx << endl;
	int last = 2;
	int cnt = 0;
	for (int j = 1; j <= n; j++) {
		while (last * 2 <= j) {
			if (g[last].size() == 1) cnt--;
			last++;
		}
		if (g[j].size() == 1) cnt++;
		if (g[j].size() > cnt+1) {
			//cout << "! " << j << "\n";
			//cout << g[j].size() << endl;
			//cout << cnt << endl;
		}
	}
	if (ans < k) {
		cout << "No" << endl;
		return;
	}
	ans = 0;
	int t = 0;
	while (ans < k) {
		ans += g[t].size();
		t++;
	}
	t--;
	if (ans == k) {
		cout << "Yes\n";
		cout << t << "\n";
		for (int i = 1; i <= t; i++) {
			printf("%d ", i);
		}
		return;
	}
	for (int i = 1; i <= t; i++) {
		if (ans - k == g[i].size() + t/i-1) {
			cout << "Yes\n";
			cout << t - 1 << "\n";
			for (int j = 1; j <= t; j++) {
				if(j!=i) printf("%d ", j);
			}
			return;
		}
	}
	vector<int> D;
	for (int i = 1; i <= t; i++) {
		if (i + i > t && g[i].size() == 1) {
			D.pb(i);
		}
	}
	vector<int> G(n * 2+10, 0);
	
	if (D.size() >= ans - k) {
		cout << "Yes\n";
		int dd = ans - k;
		for (int j = 1; j <= t; j++) G[j] = 1;
		for (int j = 0; j < dd; j++) G[D[j]] = 0;
		D.clear();

		for (int j = 1; j <= t; j++)
			if (G[j]) {
				D.pb(j);
			}
		cout << D.size() << "\n";
		for (int j = 0; j < D.size(); j++) {
			printf("%d ", D[j]);
		}
		return;
	}
	if (t <= 20) {
		for (int i = 0; i < (1<<t); i++) {
			int cur = 0;
			for (int j = 0; j < t; j++) {
				if (i&(1 << j)) {
					for (int x = j + 1; x < t; x++) {
						if ((i&(1 << x)) && (x+1) % (j+1) == 0) {
							cur++;
						}
					}
				}
			}
			if (cur == k) {
				cout << "Yes\n";
				D.clear();
				for (int x = 0; x < t; x++) {
					if ((i&(1 << x))) {
						D.pb(x+1);
					}
				}
				cout << D.size() << "\n";
				for (int j = 0; j < D.size(); j++) {
					printf("%d ", D[j]);
				}
				return;
			}
		}
	}
	D.clear();
	for (int i = 1; i <= t; i++) {
		if (g[i].size() == 1) D.pb(i);
	}
	int CC = 0;
	reverse(all(D));
	int pr = min(20, (int)D.size());
	for (int i = 0; i < (1 << pr); i++) {
		int cur = ans;
		for (int j = 0; j < pr; j++) {
			if (i&(1 << j)) cur -= t / D[j];
		}
		if (cur == k) {
			cout << "Yes\n";

			for (int x = 0; x < pr; x++) {
				if ((i&(1 << x))) {
					G[D[x]] = 1;
				}
			}
			D.clear();
			for (int j = 1; j <= t; j++) if (G[j] == 0) D.pb(j);
			cout << D.size() << "\n";
			for (int j = 0; j < D.size(); j++) {
				printf("%d ", D[j]);
			}
			return;
		}
	}
	assert(false);
	cout << "No" << endl;
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int t = 1;
	
	for (int i = 1; i <= t; i++) {
		//printf("Case #%d\n", i);
		solve();
	}
	char c;
	//cin >> c;
	return 0;
}