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
		int n;
		string s;
		cin >> n >> s;
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (i < n/2) {
					cout << i + 1 << " " << n << " " << i + 2 << " " << n << '\n';
					flag = 1;
					break;
				}
				else {
					cout << 1 << " " << i + 1 << " " << 1 << " " << i << '\n';
					flag = 1;
					break;
				}
			}
		}
		if (!flag) {
			int x = n/2;
			cout << 1 << " " << x << " " << x + 1 << " " << 2 * x << '\n';
		}
	}
}