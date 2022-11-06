#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n;
	cin >> n;
	cout << (n % 4 == 0 || n % 4 == 3 ? 0 : 1);
	return 0;
}