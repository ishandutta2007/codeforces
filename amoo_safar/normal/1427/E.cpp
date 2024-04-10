// I'll Crush you !
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

vector<pair<char, pll>> A;


void Solve(ll x){
	//cerr << "! " << x << '\n';
	if(x == 3){
		A.pb({'+',{ 3, 3}});
		A.pb({'^',{ 3, 6}});
		A.pb({'+',{ 3, 5}});
		A.pb({'+',{ 3, 6}});
		A.pb({'^',{ 8, 9}});
		return ;
	}
	assert(x % 2 == 1);
	/*
	for(int i = 2; i < Log; i++){
		if((1ll << i) == x + 1){
			A.pb({'+', {x, x}});
			A.pb({'^', {x, x + x}});
			Solve(x ^ (x + x));
			return ;
		}
	}
	*/
	ll idx = Log;
	for(int i = 2; i < Log; i++){
		if((1ll << i) > x + 1){
			idx = i;
			break;
		}
	}
	bool fl = false;
	ll z = -1;
	for(int i = 1; i <= (1ll << idx); i++){
		if((x * i) % (1ll << idx) == 1){
			fl = true;
			z = i;
		}
	}

	assert(fl);

	vector<pair<char, pll>> B;
	ll zz = z;
	while(z > 1){
		if(z & 1){
			B.pb({'+', {x, x * (z - 1)}});
			z --;
		} else {
			z /= 2;
			B.pb({'+', {x*z, x * z}});
		}
	}
	reverse(all(B));
	for(auto X : B) A.pb(X);
	A.pb({'+', {x, zz * x}});
	A.pb({'^', {x * (zz + 1), zz * x}});
	/*
	cerr << "? " << (x * (zz)) % (1ll << idx) << '\n';
	cerr << "?? " << (x * (zz + 1)) % (1ll << idx) << '\n';
	cerr << "??? " << (x * (zz + 1)) % (1ll << idx) << '\n';
	*/
	assert(((x * (zz + 1)) ^ ( zz * x)) == x + 2);
	//Solve((x * (zz + 1)) ^ ( zz * x));

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	Solve(n);
	Solve(n + 2);
	if((n ^ (n + 2)) == 2){
		A.pb({'^', {n, n + 2}});
	} else if(((n + 2) ^ (n + 4)) == 2){
		A.pb({'^', {n + 4, n + 2}});
	} else {
		assert(0);
	}
	ll la = 2;
	for(int i = 2; i < Log; i++){
		A.pb({'+', {la, la}});
		la += la;
	}
	for(int i = 1; i < Log; i++){
		if(n >> i & 1){
			ll U = (1ll << i);
			A.pb({'^', {n, U}});
			n ^= U;
		}
	}
	cout << A.size() << '\n';
	for(auto el : A) cout << el.S.F << ' ' << el.F << ' ' << el.S.S << '\n';
	return 0;
}