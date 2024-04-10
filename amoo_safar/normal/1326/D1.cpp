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

const ll Mod = 1e9 + 9;
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
const ll Base = 41;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll pw[N];
ll n, ph[N], sh[N];
str s;
void Calc(){
	ph[0] = 0;
	for(int i = 1; i <= n; i++) ph[i] = (ph[i - 1] * Base + (s[i - 1] - 1)) % Mod;
	sh[n] = 0;
	for(int i = n - 1; i >= 0; i--) sh[i] = (sh[i + 1] * Base + (s[i] - 1)) % Mod;
}
ll Getp(int l, int r){
	return (ph[r] - mul(pw[r - l], ph[l]) + Mod) % Mod;
}
ll Gets(int l, int r){
	return (sh[l] - mul(sh[r], pw[r - l]) + Mod) % Mod;
}
bool Pal(int l, int r){
	if(l < 0 || r > n) return false;
	return Getp(l, r) == Gets(l, r);
}

ll L[N], R[N];

int Main(){
	cin >> s;
	n = s.size();
	ll ans = -1;
	
fill(L, L + n + 2, 0);
fill(R, R + n + 2, 0);

	Calc();
	L[0] = 0;
	L[(n + 1) / 2] = (n & 1);
	for(int i = ((n + 1)/2) + 1; i <= n; i++){
		L[i] = L[i - 1] + 2;
		while((!Pal(i - L[i], i))) L[i] --;
	}
	R[n / 2] = (n & 1);
	
	for(int i = (n / 2) - 1; i >= 0; i--){
		R[i] = R[i + 1] + 2;
		while((!Pal(i, i + R[i])) ) R[i] --;
	}
	//debug(L[n]);
	int pp;
	int st = 0, fn = 0;

	for(int i = 0; i <= n - i; i++){
		pp = n - i;
		if(ph[i] != sh[pp]) continue;
		//ans = max(ans, i + i + max(L[pp], R[i]));
		if(i + i + L[pp] > ans){
			ans = i + i + L[pp];
			st = i;
			fn = i + L[pp];
		}
		if(i + i + R[i] > ans){
			ans = i + i + R[i];
			st = i + R[i];
			fn = i;
		}
	}
	//debug(st);
	//debug(fn);
	cout << s.substr(0, st) << s.substr(n - fn, fn) << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pw[0] = 1;
	for(int i = 1; i < N; i++) pw[i] = mul(pw[i - 1], Base);
	ll T;
	cin >> T;
	while(T--) Main();
	return 0;
}
/*
1
abcdfdcecba

*/