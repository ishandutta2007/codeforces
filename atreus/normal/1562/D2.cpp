#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 15;

int a[MAXN], b[MAXN];
int ans[MAXN], opt[MAXN][2];
map<int,int> last;
pair<pair<int,int>, int> Q[MAXN];

void solve() {
	last.clear();
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '+')
			a[i + 1] = 1;
		else
			a[i + 1] = -1;
		
		if (i & 1)
			a[i + 1] *= -1;

		a[i + 1] += a[i];
		b[i + 1] = a[i] + a[i + 1];
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		if (a[r] == a[l - 1])
			ans[i] = 0;
		else if ((a[r] - a[l - 1]) & 1)
			ans[i] = 1;
		else {
			ans[i] = 2;
			opt[i][1] = r;
			r--;
		}
		Q[i] = {{r, l}, i};
	}
	sort(Q, Q + q);
	int ptr = 1;
	for (int i = 0; i < q; i++) {
		int l = Q[i].first.second, r = Q[i].first.first, idx = Q[i].second;
		if (a[r] - a[l - 1] == 0)
			continue;
		while (ptr <= r)
			last[b[ptr++]] = ptr;
		opt[idx][0] = last[a[r] + a[l - 1]];
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
		for (int j = 0; j < ans[i]; j++)
			cout << opt[i][j] << " \n"[j == ans[i] - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
}