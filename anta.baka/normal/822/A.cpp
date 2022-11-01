#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int c = min(a, b);
	unsigned long long ans = 1;
	for(int i = 1; i <= c; i++)
		ans *= i;
	cout << ans;
}