#include<bits/stdc++.h>

using namespace std;

struct Song {
	int t, b;
} s[300005];

int n, k;

bool cmp(Song x, Song y) {
	return (x.b > y.b);
}
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].t >> s[i].b;
	}
	sort(s + 1, s + 1 + n, cmp);
	long long maxSum = 0, cnt = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt < k) {
			maxSum += s[i].t;
			cnt++;
			pq.push(s[i].t);
		} else {
			if (pq.top() < s[i].t) {
				maxSum = maxSum - pq.top() + s[i].t;
				pq.pop();
				pq.push(s[i].t);
			}
		}
		ans = max(ans, 1LL * maxSum * s[i].b);
	}
	cout << ans;
	return 0;
}