#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool dp[(int)2e5 + 99];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;


	int i = 0;
	for(int step = 1; step <= n; ++step) {
		int x;
		cin >> x;
		if(x > i) {
			cout << step;
			return 0;
		}
		dp[x] = 1;
		while(dp[i]) ++i;
	}
cout << -1;
	return 0;
}