# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int t, n;
ll x;
ll a[NR];
int main(){
	cin >> t;
	while (t--){
		cin >> n >> x;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		ll tol = 0;
		int cnt = 0;
		while (++cnt <= n){
			int nw = n - cnt + 1;
			if (tol + a[nw] < cnt * x) break;
			tol += a[nw];
		}
		cout << cnt - 1 << endl;
	}
	return 0;
}