#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --) {
		int n;
		string s;
		cin >> n >> s;
		string t = s;
		sort(t.begin(), t.end());
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (s[i] != t[i])
				cnt ++;
		cout << cnt << '\n';
	}
}