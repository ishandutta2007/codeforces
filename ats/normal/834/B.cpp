#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	int st[26];
	int ed[26];
	vector<int> cnt(n + 1, 0);
	for (int i = 0; i < 26; i++) {
		st[i] = -1;
		ed[i] = -1;
	}
	int x;
	for (int i = 0; i < n; i++) {
		x = (int)(s[i] - 'A');
		if (st[x] == -1) {
			st[x] = i;
		}
		ed[x] = i;
	}
	for (int i = 0; i < 26; i++) {
		if (st[i] != -1)cnt[st[i]] += 1;
		if (ed[i] != -1)cnt[ed[i] + 1] += -1;
	}
	int res = cnt[0];
	for (int i = 1; i <= n; i++) {
		cnt[i] += cnt[i - 1];
		res = max(res, cnt[i]);
	}
	cerr << cnt[n] << endl;
	if (res <= k) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
}