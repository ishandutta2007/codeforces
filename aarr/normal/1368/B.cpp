#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const long long inf = 1ll * 1e9 * 1e9;

int a[20];
string s = "codeforces";

long long f() {
	long long ans = 1;
	for (int i = 0; i < 10; i++) {
		ans *= a[i];
	}
	return ans;
}

int main() {
	ios :: sync_with_stdio(false);
	long long k;
	cin >> k;
	while (f() < k) {
		for (int i = 0; i < 10; i++) {
			a[i]++;
			if (f() >= k) {
				break;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < a[i]; j++) {
			cout << s[i];
		}
	}
	return 0;
}