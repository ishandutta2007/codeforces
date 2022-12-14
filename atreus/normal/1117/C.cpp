/**
 *    author:  Lord Albus Dumbledure
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;

ll x[maxn], y[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int x1, y1,
		x2, y2;
	cin >> x1 >> y1
		>> x2 >> y2;
	int n;
	string s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++){
		x[i] = x[i - 1] + (s[i - 1] == 'R') - (s[i - 1] == 'L');
		y[i] = y[i - 1] + (s[i - 1] == 'U') - (s[i - 1] == 'D');
	}
	ll lo = -1, hi = 1e18;
	while (hi - lo > 1){
		ll mid = (lo + hi) >> 1;
		ll X = (mid / n) * x[n] + x[mid % n];
		ll Y = (mid / n) * y[n] + y[mid % n];
		X += x1, Y += y1;
		if (abs(X - x2) + abs(Y - y2) <= mid)
			hi = mid;
		else
			lo = mid;
	}
	if (hi == 1e18)
		return cout << -1 << endl, 0;
	cout << hi << endl;
}