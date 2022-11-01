#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	if(n == 1)
	    return cout << 1 << "\n" << 1, 0;
	if(n == 2)
	    return cout << 1 << "\n" << 1 << ' ' << 1, 0;
	vector<bool> prime(n + 2, true);
	for(int i = 2; i * i <= n + 1; i++)
		if(prime[i])
			for(int j = i * i; j <= n + 1; j += i)
				prime[j] = false;
	cout << 2 << "\n";
	for(int i = 2; i <= n + 1; i++)
		if(prime[i])
			cout << 1 << ' ';
		else
			cout << 2 << ' ';
}