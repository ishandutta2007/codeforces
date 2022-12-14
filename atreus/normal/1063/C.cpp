#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2000 + 10;
const int N = 1000 * 1000 * 1000;
map<string, bool> mp;

bool rep(ll x, int y = 0){
	if (x > N){
		y = x - N;
		x = N;
	}
	cout << x << " " << y << endl;
	string k;
	cin >> k;
	if (mp.count(k))
		return mp[k];
	mp[k] = 0;
	if (k == "black")
		mp["white"] = 1;
	else
		mp["black"] = 1;
	return mp[k];
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll lo = 0, hi = 2000ll * 1000ll * 1000;
	rep(0);
	for (int i = 1; i < n; i++){
		ll mid = (lo + hi) >> 1;
		bool me = rep(mid);
		if (me == 0)
			lo = mid;
		else
			hi = mid;
	}
	lo ++;
	if (lo < N)
		cout << lo << " " << 0 << " " << lo << " " << 1 << endl;
	else if (lo == N)
		cout << N << " " << 0 << " " << 0 << " " << N << endl;
	else{
		lo -= N;
		cout << 0 << " " << lo << " " << 1 << " " << lo << endl;
	}
}