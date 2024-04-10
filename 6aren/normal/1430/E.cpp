#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
string s;
vector<int> pos[26];
vector<int> pos_rev[26];
int a[N];
int bit[N];

void update(int k) {
	for (int i = k; i < N; i += (i & (-i)))
		bit[i]++;
}

int get(int k) {
	int res = 0;
	for (int i = k; i > 0; i -= (i & (-i)))
		res += bit[i];
	return res;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		char ch = s[i];
		pos[ch - 'a'].push_back(i);
	}

	reverse(s.begin(), s.end());

	for (int i = 0; i < n; i++) {
		char ch = s[i];
		pos_rev[ch - 'a'].push_back(i);
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < pos[i].size(); j++)
			a[pos[i][j]] = pos_rev[i][j];
	}

	long long ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		ans += get(a[i] + 1);
		update(a[i] + 1);
	}


	cout << ans << '\n';

	return 0;
}