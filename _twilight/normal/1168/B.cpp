#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e5 + 5;

#define ll long long

int n;
int R[N];
char s[N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		R[i] = n + 1; 
		for (int j = 1; j <= 20 && (i + 2 * j <= n); j++) {
			if (s[i] == s[i + j] && s[i + j] == s[i + j * 2]) {
				R[i] = i + j * 2;
				break;
			}
		}
	}
	for (int i = n - 1; i; i--) {
		R[i] = min(R[i], R[i + 1]);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (R[i] <= n) {
			ans += n - R[i] + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}