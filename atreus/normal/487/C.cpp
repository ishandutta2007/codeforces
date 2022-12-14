#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
int n;

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a, b / 2);
	ret = 1ll * ret * ret % n;
	if (b & 1)
		ret = 1ll * ret * a % n;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	if (n == 4)
		return cout << "YES\n1 3 2 4\n", 0;
	int cnt = 2;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			cnt ++;
	if (cnt >= 3)
		return cout << "NO\n", 0;
	// if n is prime
	cout << "YES\n";
	cout << 1 << " ";
	for (int i = 2; i <= n; i++){
		int t = 1ll * i * power(i - 1, n - 2) % n;
		if (t == 0)
			t = n;
		cout << t << " ";
	}
	cout << '\n';
}