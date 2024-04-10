#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const ll inf = 1e18;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		cout << min(n - 1, abs(a - b) + x) << '\n';
	}
}