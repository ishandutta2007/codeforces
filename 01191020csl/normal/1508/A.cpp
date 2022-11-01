#include<bits/stdc++.h>
using namespace std;
string tmp[100001];
void solve(string s1, string s2, int typ) {
	int n = s1.size() / 2, cnt = 0;
	for (int i = 0; i <= n; i++) tmp[i].clear();
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == typ+'0' && cnt < n) ++cnt;
		else tmp[cnt].push_back(s1[i]);
	}
	cnt = 0;
	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] == typ+'0' && cnt < n) ++cnt;
		else tmp[cnt].push_back(s2[i]);
	}
	cout << tmp[0];
	for (int i = 1; i <= n; i++) cout << typ << tmp[i];
	cout << endl;	
}
int main() {
//	freopen("A.in", "r", stdin);
//	freopen("A.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s[3];
		cin >> s[0] >> s[1] >> s[2];
		int c[3] = {0, 0, 0};
		for (int i = 0; i < n * 2; i++)
			for (int j = 0; j < 3; j++)
				c[j] += s[j][i] - '0';
		bool flag = 0;
		for (int i = 0; !flag && i < 3; i++)
			for (int j = i + 1; !flag && j < 3; j++) {
				if (c[i] > n && c[j] > n) solve(s[i], s[j], 1), flag = 1;
				if (c[i] <= n && c[j] <= n) solve(s[i], s[j], 0), flag = 1;
			}
	}
}