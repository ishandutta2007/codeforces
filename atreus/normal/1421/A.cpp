#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int a, b;
		cin >> a >> b;
		int ans = 0;
		for (int i = 0; i < 30; i++){
			int y = a&1, x = b&1;
			if (x^y)
				ans += (1 << i);
			a /= 2, b /= 2;
		}
		cout << ans << '\n';
	}
}