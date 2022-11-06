#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = (int) 3e5 + 9;
vector<int> adj[MxN + 9];
int a[MxN + 9];
int cnt[MxN + 9];
int rnk[MxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		adj[p].push_back(i);
	}

	for (int i = n; i >= 1; --i) {
		if (adj[i].empty())
			cnt[i] = rnk[i] = 1;
		else {
			for (int x : adj[i])
				cnt[i] += cnt[x];

			if (a[i] == 0) { // min
				int sum = 0;
				for (int x : adj[i])
					sum += cnt[x] - rnk[x] +1 ;
				rnk[i] = cnt[i] - sum + 1;
			} else { // max
				assert(a[i] == 1);
				int diff = n + 9;
				for (int x : adj[i])
					diff = min(diff, cnt[x] - rnk[x]);
				rnk[i] = cnt[i] - diff;
			}
		}
	}
	cout << rnk[1];
	return 0;
}