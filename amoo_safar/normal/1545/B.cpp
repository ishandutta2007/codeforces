// vaziat meshki-ghermeze !
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

const ll Mod = 998244353ll;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll f[N];
ll iv[N];
ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw))
		if(p & j)
			res = mul(res, pw);
	return res;
}
ll nCr(ll n, ll r){
	return mul(f[n], mul(iv[r], iv[n - r]));
}

int Main(){
	int n;
	cin >> n;
	str s;
	cin >> s;
	int u = 0;
	vector<int> V = {0};
	int sm = 0;
	for(auto x : s){
		if(x == '1') sm ++, u ^= 1;
		else V.pb(u);
	}
	V.pb(u);

	int cnt = 0;
	for(int i = 0; i + 1 < (int) V.size(); i++) if(V[i] != V[i + 1])
		cnt ++;
	assert(cnt <= sm);
	sm -= cnt;
	assert(sm % 2 == 0);
	sm /= 2;
	int m = V.size() - 1;
	cout << nCr(sm + m - 1, m - 1) << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = mul(f[i - 1], i);
	for(int i = 0; i < N; i++) iv[i] = bin_pow(f[i], Mod - 2);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}