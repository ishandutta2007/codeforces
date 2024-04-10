#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int s[1000001], d[1000001];
int main() {
	int n;
	cin >> n;
	s[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			++d[j];
	for (int i = 1; i <= n; i++) s[i] = (2ll*s[i-1] + d[i] - 1) % mod;
	cout << (mod + s[n] - s[n-1]) % mod << endl;
}