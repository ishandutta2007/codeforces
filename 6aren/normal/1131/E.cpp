#include <bits/stdc++.h>

using namespace std;

int n;

string s[100005];

void swap(string &x, string &y) {
	string tg = x;
	x = y;
	y = tg;
	return;
}

int sta, dp[100005];

int main() {
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n / 2; i++) {
		swap(s[i], s[n - i + 1]);
	}
	int res = 1;
	for (int i = 1; i < s[1].size(); i++) {
		if (s[1][i] != s[1][i - 1]) {
			res = 1;
		} else {
			res++;
		}
		dp[1] = max(dp[1], res);
	}
	if (s[1][0] == s[1][s[1].size() - 1]) {
		sta = 0;
	} else {
		sta = 1;
	}
	int head = 1;
	for (int i = 1; i < s[1].size(); i++) {
		if (s[1][i] == s[1][i - 1]) {
			head++;
		} else break;
	} 
	int tail = 1;
	for (int i = 1 * s[1].size() - 2; i >= 0; i--) {
		if (s[1][i + 1] == s[1][i]) {
			tail ++;
		} else break;
	}
	int maxi = dp[1];

 	if (sta == 1) {
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < s[i].size(); j++) {
				if (s[i][j] == s[1][0] && head == dp[1]) {
					maxi = head + 1;
				} else if (s[i][j] == s[1][s[1].size() - 1] && tail == dp[1]) {
					maxi = tail + 1;
				}
			}
		}
		cout << maxi << endl;
		return 0;
	}
	if (sta == 0 && head < s[1].size()) {
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < s[i].size(); j++) {
				if (s[i][j] == s[1][0]) {
					maxi = max(maxi, head + tail + 1);
				}
			}
		}
		cout << maxi << endl;
		return 0;
	}
	if (sta == 0) {
		for (int i = 2; i <= n; i++) {
			if (sta == 0) {
				int ans = 0;
				int maxx = 0;
				for (int j = 0; j < s[i].size(); j++) {
					if (s[i][j] == s[1][0]) {
						ans++;
						maxx = max(maxx, ans);
					} else {
						ans = 0;
					}
				}
				int cnthe = 0, cntta = 0;
				for (int j = 0; j < s[i].size(); j++) {
					if (s[i][j] == s[1][0]) {
						cnthe++;
					} else {
						break;
					}
				}
				for (int j = s[i].size() - 1; j >= 0; j--) {
					if (s[i][j] == s[1][0]) {
						cntta++;
					} else {
						break;
					}
				}
				if (maxx != s[i].size()) {
					sta = 1;
					dp[i] = (maxx + 1) * head + maxx;
					head = (cnthe + 1) * head + cnthe;
					tail = (cntta + 1) * tail + cntta;
				} else {
					head = s[i].size() + (s[i].size() + 1) * head;
					tail = head;
					dp[i] = head;
				}
				maxi = max(maxi, dp[i]);
			} else if (sta == 1) {
				for (int j = 0; j < s[i].size(); j++) {
					if (s[i][j] == s[1][0]) {
						maxi = max(maxi, head + tail + 1);
					}
				}
			}
		}
		cout << maxi << endl;
	}
	return 0;
}

//g++ online.cpp -o online.exe