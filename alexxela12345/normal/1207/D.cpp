#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

int mul(int a, int b) {
	return a * b % MOD;
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second < b.second;
}

const int MAXN = 3e5 + 228;

int fact[MAXN];


signed main() {
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = mul(fact[i - 1], i);
	}
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());
	int cnt12 = 1;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i].second > arr[i + 1].second) {
			cnt12 = 0;
			break;
		}
	}
	if (cnt12 == 1) {
		int cur_cnt = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i] == arr[i - 1]) {
				cur_cnt++;
			} else {
				cnt12 = mul(cnt12, fact[cur_cnt]);
				cur_cnt = 1;
			}
		}
		cnt12 = mul(cnt12, fact[cur_cnt]);
	}
	int cnt1 = 1;
	int cur_cnt = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i].first == arr[i - 1].first) {
			cur_cnt++;
		} else {
			cnt1 = mul(cnt1, fact[cur_cnt]);
			cur_cnt = 1;
		}
	}
	cnt1 = mul(cnt1, fact[cur_cnt]);
	sort(arr.begin(), arr.end(), cmp);
	int cnt2 = 1;
	cur_cnt = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i].second == arr[i - 1].second) {
			cur_cnt++;
		} else {
			cnt2 = mul(fact[cur_cnt], cnt2);
			cur_cnt = 1;
		}
	}
	cnt2 = mul(cnt2, fact[cur_cnt]);
	int ans = fact[n] - cnt1 - cnt2 + cnt12;
	ans %= MOD;
	ans += MOD;
	ans %= MOD;
	cout << ans << endl;
}