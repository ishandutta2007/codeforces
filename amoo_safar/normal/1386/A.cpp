// Null
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int Ask(ll P){
	cout << "? " << P << endl;
	int res;
	cin >> res;
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll T;
cin >> T;
while(T --){
	ll n;
	cin >> n;
	ll l = 0, r = n, mid;
	vector<ll> V;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		V.pb(mid);
		l = mid;
	}
	reverse(all(V));
	ll z = -1;
	ll st = n;
	for(auto x : V){
		st += z * x;
		z *= -1;
	}
	Ask(st);
	ll la = st;
	l = 0, r = n;//, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;

		if(Ask(la + z * mid)) r = mid;
		else l = mid;
		la = la + z*mid;
		z *= -1;
	}
	cout << "= " << r << endl;
	
}
	return 0;
}