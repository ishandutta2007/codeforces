#include <bits/stdc++.h>
#define bit(n, k) (((n)>>(k))&1)
using namespace std;

const int maxn = 1e5 + 1;

int a[maxn], l[maxn], pre[maxn], dp[maxn];
long long ps[maxn];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int x;
	cin >> x;
	for (int i = 1; i <= n; i++) {
		a[i] -= x;
		ps[i] = ps[i - 1] + a[i];
	}
	pre[0] = -1;
	l[1] = -1;
	for (int i = 2; i <= n; i++) {
		pre[i] = i - 2;
		while (pre[i] != -1 and ps[pre[i]] <= ps[i])
			pre[i] = pre[pre[i]];
		if (pre[i] != -1)
			l[i] = pre[i];
		else
			l[i] = -1;

		int j = i - 1;
		pre[j] = j - 1;
		while (pre[j] != -1 and ps[pre[j]] <= ps[j])
			pre[j] = pre[pre[j]];
	}
	deque<int> Deq;
	Deq.push_front(0);
	dp[0] = 0;
	l[0] = -1;
	for (int i = 1; i <= n; i++) {
		while (!Deq.empty() and Deq.back() <= l[i - 1])
			Deq.pop_back();
		if (Deq.empty())
			dp[i] = n + 10;
		else
			dp[i] = dp[Deq.back()] + 1;
		while (!Deq.empty() and dp[Deq.front()] >= dp[i])
			Deq.pop_front();
		Deq.push_front(i);
	}
	int answer = n;
	int maxL = -1;
	for (int i = n; i >= 0; i--) {
		maxL = max(maxL, l[i]);
		if (i <= maxL)
			break;
		answer = min(answer, dp[i]);
	}
	cout << n - answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int tc;
	cin >> tc;
	while (tc --) {
		solve();
	}
}