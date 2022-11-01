#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, len[999999], A[100000], H[100000];
vector<pair<int, int>> q[1000000];
vector<int> vec[2000001];
int cnt[100000];
ll sum[100000];

void go(int v) {
	if(v >= n) return;
	go(v * 2 + 1);
	go(v * 2 + 2);
	for(int i = 0; i < vec[v * 2 + 1].size(); i++) vec[v * 2 + 1][i] += len[v * 2];
	for(int i = 0; i < vec[v * 2 + 2].size(); i++) vec[v * 2 + 2][i] += len[v * 2 + 1];
	vec[v] = {0};
	merge(vec[v * 2 + 1].begin(), vec[v * 2 + 1].end(), vec[v * 2 + 2].begin(), vec[v * 2 + 2].end(), back_inserter(vec[v]));
	vector<ll> p(vec[v].size());
	p[0] = vec[v][0];
	for(int i = 1; i < vec[v].size(); i++) p[i] = p[i - 1] + vec[v][i];
	for(int i = 0; i < q[v].size(); i++) {
		int x = q[v][i].first, id = q[v][i].second;
		if(vec[v][0] >= x) continue;
		int lf = 0, rg = vec[v].size() - 1;
		while(lf < rg) {
			int md = (lf + rg) / 2;
			if(lf == md) md++;
			if(vec[v][md] < x) lf = md;
			else rg = md - 1;
		}
		if(id < 0) {
			id = -id - 1;
			cnt[id] -= lf + 1;
			sum[id] -= (lf + 1LL) * (H[id] - x) + p[lf];
		} else {
			id--;
			cnt[id] += lf + 1;
			sum[id] += (lf + 1LL) * (H[id] - x) + p[lf];
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n - 1; i++) cin >> len[i];
	for(int i = 0; i < m; i++) {
		cin >> A[i] >> H[i]; A[i]--;
		q[A[i]].push_back({H[i], i+1});
		int v = A[i], l = H[i];
		while(v != 0) {
			if(len[v - 1] >= l) break;
			q[v].push_back({l - 2 * len[v - 1], -(i+1)});
			l -= len[v - 1];
			v = (v - 1) / 2;
			q[v].push_back({l, i+1});
		}
	}
	go(0);
	for(int i = 0; i < m; i++) {
		cout << (ll)H[i] * cnt[i] - sum[i] << '\n';
	}
}