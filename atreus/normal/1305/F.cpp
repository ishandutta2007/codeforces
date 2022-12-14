#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;

ll a[maxn];
int n, answer;
map<ll, int> mp;

int check(ll x){
	if (x <= 1)
		return n;
	if (mp.count(x))
		return mp[x];
	ll ret = 0;
	for (int i = 0; i < n; i++){
		if (a[i] < x){
			ret += x - a[i];
			continue;
		}
		ret += min(a[i] % x, x - (a[i] % x));
	}
	if (ret > n)
		ret = n;
	return mp[x] = ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int t = 70;
	answer = min({check(2), check(3), check(5), check(7), check(11), check(13), check(17), check(19), check(23)});;
	while (t --){
		int i = rng() % n;
		ll x = a[i];
		int t = rng() % 3 - 1;
		x += t;
		for (ll y = 2; y * y <= x; y++){
			if (x % y == 0){
				answer = min(answer, check(y));
				while (x % y == 0)
					x /= y;
			}
		}
		if (x != 1)
			answer = min(answer, check(x));
	}
	cout << answer << endl;	
}