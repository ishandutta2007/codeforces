#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main() {
	long long n, k, s[N];
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> s[i];
	
	long long ret = s[n];
	for (int i = n - k; i >= 1; i--) ret = max(ret, s[i] + s[n - k + n - k + 1 - i]);
	cout << ret << endl;
	return 0;
}