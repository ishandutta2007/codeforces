#include <bits/stdc++.h> 

using namespace std;

const int M = 1550;
const int N = 1e5 + 10;

int n, k;
long long f[70];

int main (int argc, char const *argv[]) {
	int now = 0;
	for (int i = 0; i <= 60; ++i) {
		for (int j = i; j <= i + now; ++j) {
			f[j] = now;
		}
		i += now;
		++now;
	}
	// for (int i = 0; i <= 20; ++i) cout << f[i] << " "; cout << endl;
	scanf("%d", &n);
	long long sum = 0LL;
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		sum ^= f[x];
	}
	puts(sum == 0 ? "YES" : "NO");
	return 0;
}