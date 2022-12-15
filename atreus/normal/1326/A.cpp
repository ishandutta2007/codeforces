#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		if (n == 1){
			cout << -1 << '\n';
			continue;
		}
		for (int i = 1; i <= n - 1; i++)
			cout << 3;
		cout << 4;
		cout << '\n';
	}
}