// Zende bad Shoma nasime faghat !
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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll c1[N], c2[N], c3[N];
str s[N];
ll n;

pll Check(ll x){
	ll Lx = 0, Rx = Inf;
	for(int i = 0; i < n; i++){
		Lx = max(Lx, c1[i] - x);
		Rx = min(Rx, c1[i] + x);
	}
	ll Ly = 0, Ry = Inf;
	for(int i = 0; i < n; i++){
		Ly = max(Ly, c2[i] - x);
		Ry = min(Ry, c2[i] + x);
	}
	ll Ld = -Inf, Rd = Inf;
	for(int i = 0; i < n; i++){
		Ld = max(Ld, c3[i] - x);
		Rd = min(Rd, c3[i] + x);
	}
	if(Lx > Rx) return pll(0, 0);
	if(Ly > Ry) return pll(0, 0);
	if(Ld > Rd) return pll(0, 0);

	ll Bo = 1'000'000;
	ll RY, RX;
	for(int X = Lx; X <= min(Rx, Bo); X++){
		ll Y1 = Ld + X;
		ll Y2 = Rd + X;
		if(max(Y1, Ly) <= min(Y2, Ry)){
			RY = min(Y2, Ry);
			if(RY + X > 0) return pll(X, RY);
		}
	}
	return pll(0, 0);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		for(auto c : s[i]){
			if(c == 'B') c1[i] ++;
			else c2[i] ++;
		}
		c3[i] = c2[i] - c1[i];
		//cerr << c1[i] << ' ' << c2[i] << '\n';
	}
	int L = -1, R = 1e7;
	int mid;
	while(L + 1 < R){
		mid = (L + R) >> 1;
		if(Check(mid) != pll(0, 0)) R = mid;
		else L = mid;
	}
	cout << R << '\n';
	pll res = Check(R);
	//cerr << res.F << ' ' << res.S << '\n';
	
	for(int i = 0; i < res.F; i++) cout << 'B';
	for(int i = 0; i < res.S; i++) cout << 'N';
	cout << '\n';
	return 0;
}