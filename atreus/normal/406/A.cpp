#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e6 + 10;
const ll mod = 1e9 + 7;

int a[1100][1010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int now = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		now ^= a[i][i];
	int q;
	cin >> q;
	while (q --){
		int t, x;
		cin >> t;
		if (t != 3){
			cin >> x;
			now ^= 1;
		}
		else
			cout << now;
	}
	cout << '\n';
}