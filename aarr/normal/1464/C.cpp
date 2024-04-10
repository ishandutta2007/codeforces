#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 103;

bool mark[N];
int cnt[N];

int32_t main() {
	ios :: sync_with_stdio(false);
	int n;
	long long t;
	string s;
	cin >> n >> t >> s;
	long long sm = 0;
	t -= 1 << (s[n - 1] - 'a');
	t += 1 << (s[n - 2] - 'a');
	if (t < 0) {
		t = -t;
	}
	for (int i = 0; i + 2 < n; i++) {
		cnt[s[i] - 'a']++;
		sm += (1ll << (s[i] - 'a'));
	}
	if (sm % 2 != t % 2 || t > sm) {
		cout << "No";
		return 0;
	}
//	cout << "72 " << sm << " " << t << endl;
	t = sm - t;
	t /= 2;
//	cout << "73 " << sm << " " << t << endl;
	bool ans = true;
	for (int i = 0; i < N; i++) {
		int x = t % 2;
		t /= 2;
		if (!mark[i] && x > cnt[i] % 2) {
			ans = false;
			break;
		}
		if (cnt[i] >= 2) {
			cnt[i + 1] += cnt[i] / 2;
			mark[i + 1] = true;
		}
	}
	if (ans) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}