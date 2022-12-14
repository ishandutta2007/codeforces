#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int m = n - (n % 10);
		if (n % 7 == 0) {
			cout << n << '\n';
		}
		else {
			for (int i = 0; i < 10; i++)
				if ((m + i) % 7 == 0) {
					cout << m + i << '\n';
					break;
				}
		}
	}
}