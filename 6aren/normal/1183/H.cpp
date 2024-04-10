#include<bits/stdc++.h>

using namespace std;

long long n, k, s[30][105], cnt[105];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> k;
	string t;
	cin >> t;
	s[t[0] - 'a'][1] = 1;
	for (int i = 1; i < t.size(); i++) {
		int u = t[i] - 'a';
		for (int j = i + 1; j >= 2; j--) {
			s[u][j] = 0;
			for (int k = 0; k < 26; k++) {
				s[u][j] += s[k][j - 1];
			}
		}
		s[u][1] = 1;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= t.size(); j++) {
			cnt[j] += s[i][j];
		}
	}
	cnt[0] = 1;
	long long res = 0, id = t.size();
	while (k > 0) {
		long long u = min(k, cnt[id]);
		k -= u;
		res += (n - id) * u;
		id--;
		if (id < 0) break;
	}
	if (k > 0) return cout << -1, 0;	
	cout << res << endl;

	return 0;
}