#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cnt[10];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int t = 0;
	for(char x : s) {
		t += (x - '0');
		cnt[x - '0']++;
	}
	int ans = 0;
	for(int i = 0; i < 10 && t < n; i++)
		for(int j = 0; j < cnt[i] && t < n; j++) {
			ans++;
			t += (9 - i);
		}
	cout << ans;
}