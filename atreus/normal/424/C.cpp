#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e6 + 10;

int p[maxn], a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++)
		a[i] = (a[i - 1] ^ i);
	int answer = 0;
	for (int i = 1; i <= n; i++){
		answer ^= p[i];
		int t = (n + i) / i;
		if (t & 1)
			answer ^= a[n % i];
		else
			answer ^= (a[n % i] ^ a[i-1]);
	}
	cout << answer << '\n';
}