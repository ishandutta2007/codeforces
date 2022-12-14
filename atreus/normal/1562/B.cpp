#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isprime(int x) {
	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		int k;
		cin >> k;
		string s;
		cin >> s;
		string t = "";
		for (char c : s) {
			if (c == '1' || c == '4' || c == '6' || c == '8' || c == '9') {
				t = c;
				break;
			}
		}
		for (int i = 0; t.empty() and i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				int x = (s[i] - '0') * 10 + (s[j] - '0');
				if (!isprime(x)) {
					t = to_string(x);
					break;
				}
			}
		}
		cout << t.size() << '\n';
		cout << t << '\n';
	}
}