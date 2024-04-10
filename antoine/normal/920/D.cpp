#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>

using namespace std;

int N, K, V;
int a[5001];

int modK(int n) {
	return ((n % K) + K) % K;
}

enum dpVal { notSet, yes, no };
dpVal dp[5001][5001] = { notSet };
bool choice[5001][5001];

void f() {
	for (int k = 0; k < K; ++k)
		dp[N][k] = k ? no : yes;
	for (int i = N - 1; i >= 0; --i)
		for (int k = 0; k < K; ++k) {
			if (dp[i + 1][k] == yes) {
				choice[i][k] = false;
				dp[i][k] = yes;
			}
			else if (dp[i + 1][modK(k - a[i])] == yes) {
				choice[i][k] = true;
				dp[i][k] = yes;
			}
			else
				dp[i][k] = no;
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K >> V;
	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	
	f();
	int k = V % K;
	if (sum < V || dp[0][k] == no) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	sum = 0;
	set<int> s;
	int firstChosen = -1;
	for (int i = 0; i < N; ++i) {
		if (choice[i][k]) {
			s.insert(i);
			k = modK(k - a[i]);
			sum += a[i];
			if (firstChosen == -1)
				firstChosen = i;
		}
	}
	if (firstChosen == -1) {
		firstChosen = 0;
		if (a[0])
			cout << (a[0] + K - 1) / K << " 1 2\n";
		a[1] += a[0];
		a[0] = 0;
	}
	for (int i = firstChosen + 1; i < N; ++i)
		if (s.count(i) && (a[i] + K - 1) / K)
			cout << (a[i] + K - 1) / K << ' ' << i + 1 << ' ' << firstChosen + 1 << '\n';
	const int firstUnchosen = firstChosen ? 0 : 1;
	if (sum >= V) {
		if (sum > V)
			cout << (sum - V) / K << ' ' << firstChosen + 1 << ' ' << firstUnchosen + 1 << '\n';
		return 0;
	}
	for (int i = firstUnchosen + 1; i < N; ++i)
		if (!s.count(i) && (a[i] + K - 1) / K)
			cout << (a[i] + K - 1) / K << ' ' << (i + 1) << ' ' << (firstUnchosen + 1) << '\n';
	if ((V - sum) / K)
		cout << (V - sum) / K << ' ' << firstUnchosen + 1 << ' ' << firstChosen + 1 << '\n';
	return 0;
}