#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int a[maxn], dp[maxn], pd[maxn];

string getPlayerByTurn(bool turn) {
	if (turn == 0)
		return "Alice";
	else
		return "Bob";
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dp[n] = 1;
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] < a[i + 1])
			dp[i] = dp[i + 1] + 1;
		else
			dp[i] = 1;
	}
	pd[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] < a[i - 1])
			pd[i] = pd[i - 1] + 1;
		else
			pd[i] = 1;
	}
	int ptrL = 1, ptrR = n;
	int last = -1;
	bool turn = 0;
	while (ptrL != ptrR) {
		if (last >= max(a[ptrL], a[ptrR])) {
			if (turn == 0)
				cout << "Bob\n";
			else
				cout << "Alice\n";
			return 0;
		}
		if (last >= a[ptrL]) {
			last = a[ptrR--];
			turn ^= 1;
			continue;
		}
		if (last >= a[ptrR]) {
			last = a[ptrL++];
			turn ^= 1;
			continue;
		}
		bool canIWin = false;
		if (a[ptrL] >= a[ptrR])
			canIWin |= (dp[ptrL] & 1);
		if (a[ptrL] <= a[ptrR])
			canIWin |= (pd[ptrR] & 1);
		if (canIWin) {
			if (a[ptrL] >= a[ptrR] && (dp[ptrL] & 1))
				last = a[ptrL++];
			else
				last = a[ptrR--];
		}
		else {
			if (a[ptrL] <= a[ptrR])
				last = a[ptrL++];
			else
				last = a[ptrR--];
		}
		turn ^= 1;
	}
	if (last >= a[ptrL])
		cout << getPlayerByTurn(turn^1) << '\n';
	else
		cout << getPlayerByTurn(turn) << '\n';
}