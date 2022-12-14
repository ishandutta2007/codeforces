#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;

ll n;
ll x, p, y, b;
ll k;
ll a[maxn];

bool check(ll mid){
	if (x > y){
		swap(p, b);
		swap(x, y);
	}
	ll c = lcm(p, b);
	ll num2 = mid / c;
	ll num1 = mid / b - num2;
	ll num0 = mid / p - num2;
	ll sum = 0;
	for (int i = 0; i < num2; i++)
		sum += (x + y) * a[i] / 100;
	for (int i = num2; i < num2 + num1; i++)
		sum += y * a[i] / 100;
	for (int i = num2 + num1; i < num2 + num1 + num0; i++)
		sum += x * a[i] / 100;
	return sum >= k;
}

int main(){
	ios_base::sync_with_stdio (false);
	int q;
	cin >> q;
	while (q --){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n, greater<ll>());
		cin >> x >> p >> y >> b;
		cin >> k;
		int lo = 0, hi = n + 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (check(mid))
				hi = mid;
			else
				lo = mid;
		}
		if (hi == n + 1)
			hi = -1;
		cout << hi << endl;
	}
}