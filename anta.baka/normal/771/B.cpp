#include <bits/stdc++.h>

using namespace std;

string gen(int i) {
	return string(1, char('A' + i / 26)) + string(1, char('a' + i % 26));
}

int main() {
	int n, k;
	cin >> n >> k;
	string r[n - k + 1];
	for(int i = 0; i < n - k + 1; i++)
		cin >> r[i];
	string ans[n];
	for(int i = 0; i < k - 1; i++)
		ans[i] = gen(i);
	for(int i = k - 1; i < n; i++)
		if(r[i - k + 1][0] != 'Y')
			ans[i] = ans[i - k + 1];
		else
			ans[i] = gen(i);
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}