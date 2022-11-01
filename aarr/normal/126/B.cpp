#include <iostream>
using namespace std;


const int N = 1000 * 1000 + 5;

int f[N];
int cnt[N];

int main() {
	string s;
	cin >> s;
	f[0] = -1;
	for (int i = 1; i <= s.size(); i++) {
		int t = f[i - 1];
		while (t != -1 && s[t] != s[i - 1]) {
			t = f[t];
		}
		f[i] = t + 1;
	//	cout << "71 " << i << " " << f[i] << endl;
		cnt[t + 1]++;
	}
	int ans;
	if (cnt[f[s.size()]] >= 2) {
		ans = f[s.size()];
	}
	else {
		ans = f[f[s.size()]];
	}
	if (ans <= 0) {
		cout << "Just a legend";
	}
	else {
		for (int i = 0; i < ans; i++) {
			cout << s[i];
		}
	}
	return 0;
}