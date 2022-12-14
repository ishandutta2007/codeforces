#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e6 + 10;
const ll mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n, m;
		cin >> n;
		int mx = 0, sum = 0;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			sum += x;
			mx = max(mx,sum);
		}
		cin >> m;
		int mx2 = 0;
		sum = 0;
		for (int i = 1; i <= m; i++){
			int x;
			cin >> x;
			sum += x;
			mx2 = max(mx2,sum);
		}
		cout << mx+mx2 << '\n';
	}
}