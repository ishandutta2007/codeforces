#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n; int ans = 0;
	for(int i = 1; i <= n; i++)
		if(n % i == 0) {
			int x = i;
			int k = 0;
			while(x % 2 == 0) { x /= 2; k++; }
			k++;
			if(x == (1 << k) - 1) ans = i;
		}
	cout << ans;
}