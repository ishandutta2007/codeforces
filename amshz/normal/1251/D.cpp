# include <bits/stdc++.h>

using namespace std;

const int xn = 2e5+10;

typedef long long ll;

pair <ll, ll> lr[xn];
ll n, s;

bool check(ll x){
	int q = 0, w = 0;
	ll c = 0;
	for (int i=0; i<n; i++){
		if (lr[i].second < x) w++, c += lr[i].first;
		else if (lr[i].first > x) q++, c += lr[i].first;
	}
	int t = (n-2*w);
	//t++;
	if (t < 0) return false;
	//t--;
	t /= 2;
	int p = 0;
	for (int i=0; i<n; i++){
		if (lr[i].first <= x and lr[i].second >= x and p < t) c += lr[i].first, p++;
		else if (lr[i].first <= x and lr[i].second >= x) c += x;
	}
	//cout << x << " : " << c <<  ' ' << p << ' ' << t << endl;
	if (c <= s) return true;
	return false;
}

int main(){
	int qq;
	cin >> qq;
	while (qq--){
		cin >> n >> s;
		for (int i=0; i<n; i++) cin >> lr[i].first >> lr[i].second;
		sort(lr, lr+n);
		//cout << endl;
		ll sum = 0;
		//for (int i=0; i<n; i++) cout << lr[i].first << ' ' << lr[i].second << endl, sum += lr[i].first;
		//cout << sum << endl;
		ll l = 0, r = 1e18, mid;
		while (l+1 < r){
			mid = (l+r)/2;
			if (check(mid)) l = mid;
			else r = mid;
		}
		cout << l << endl;
	}
}