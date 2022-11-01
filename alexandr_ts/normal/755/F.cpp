#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

int a[N];
bool used[N];
const int T = 100;
bitset<N> bs;
int cnt_used_x[N];

void solve1(vector<int>& lens, int n, int k) {
	sort(lens.rbegin(), lens.rend());
	bs[0] = 1;
	for (auto x: lens) {
		if (x < T) break;
		bs |= (bs << x);	
	}
	unordered_map<int, int> cnt_by_x;
	for (auto x: lens) {
		if (x < T) {
			cnt_by_x[x]++;	
		}
	}

	for (auto [x, cnt]: cnt_by_x) {
		fill(cnt_used_x, cnt_used_x + k + 1, 0);
		for (int i = 0; i <= k; ++i) {
			if (!bs[i] || cnt_used_x[i] >= cnt) continue;
			if (i + x <= k) {
				if (bs[i + x]) {
					cnt_used_x[i + x] = min(cnt_used_x[i + x], cnt_used_x[i] + 1);
				} else {
					bs[i + x] = 1;
					cnt_used_x[i + x] = cnt_used_x[i] + 1;
				}
			}
		}
	}
	if (bs[k]) {
		cout << k << " ";	
	} else {
		cout << k + 1 << " ";
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];	
		a[i]--;
	}

	vector<int> lens;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			lens.push_back(1);
			int cur = a[i];	
			used[i] = true;
			while (cur != i) {
				used[cur] = true;
				lens.back()++;	
				cur = a[cur];
			}
		}	
	}


	int cnt_even = 0, cnt_odd = 0;
	for (auto l: lens) {
		if (l % 2) {
			cnt_odd++;	
		} else {
			cnt_even++;
		} 
	}

	solve1(lens, n, k);

	int k1 = k;
	int ans2 = min(k1, (n - cnt_odd) / 2) * 2;
	k1 -= min(k1, (n - cnt_odd) / 2);
	ans2 += min(k1, cnt_odd);
	cout << ans2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}