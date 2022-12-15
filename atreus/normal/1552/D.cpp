#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 200 + 10;

int a[20];

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		string answer = "NO";
		for (int mask = 1; mask < (1 << n); mask++) {
			for (int sub = mask; ; sub = (sub - 1) & mask) {
				int sum = 0;
				for (int i = 0; i < n; i++)
					if (sub & (1 << i))
						sum += a[i];
					else if (mask & (1 << i))
						sum -= a[i];
				if (sum == 0)
					answer = "YES";
				if (sub == 0)
					break;
			}
		}
		cout << answer << endl;
	}
}