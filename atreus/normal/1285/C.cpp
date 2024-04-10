#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	ll x;
	cin >> x;
	ll ansa = x, ansb = x;
	for (ll a = 1; a * a <= x; a++){
		if (x % a != 0)
			continue;
		ll b = x / a;
		if (lcm(a, b) != x)
			continue;
		ansa = a;
		ansb = b;
	}
	cout << ansa << " " << ansb << endl;
}