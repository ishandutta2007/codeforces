#include<bits/stdc++.h>
using namespace std;

string s[1005];
int a[1005], cnt[6];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	int res = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 5; j++) {
			cnt[j] = 0; 
		}
		for (int j = 0; j < n; j++) {
			cnt[s[j][i] - 'A']++;
		}
		int id_max = 0;
		for (int j = 1; j < 5; j++) {
			if (cnt[j] > cnt[id_max]) id_max = j;
		}
		res += cnt[id_max] * a[i];
	}
	cout << res;
	return 0;
}