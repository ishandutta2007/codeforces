#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;

bool ask(ll x){
	cout << "? " << x << endl;
	bool ret;
	cin >> ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		ll n;
		cin >> n;
		ll lo = 0, hi = n;
		vector<ll> a;
		while (hi - lo > 1){
			ll m = (lo + hi) >> 1;
			a.push_back(m);
			lo = m;
		}
		ll sum = 0;
		for (int i = 0; i < a.size(); i++)
			if (i & 1)
				sum -= a[i];
			else
				sum += a[i];
		ll now;
		if (sum < 0)
			now = -sum + 1;
		else
			now = n - sum;
		ask(now);
		int sign = 1;
		lo = 0, hi = n;
		while (hi - lo > 1){
			ll mid = (lo + hi) >> 1;
			now += mid*sign;
			if (ask(now) == 0)
				lo = mid;
			else
				hi = mid;
			sign *= -1;
		}
		cout << "= " << hi << endl;
	}
}