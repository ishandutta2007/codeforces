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

const ll Mod = 998244353;
const int N = 4e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
const int Sq = 300;

typedef pair<int, int> pii;

int x[N], y[N];
int n, m;

bool ch;
int a[N], b[N];
int Get(int i){
	return ch ? a[i] : i;
}

vector<pii> V, V2;
void Break(int sz){
	if(sz == 0) return ;
	V2.clear();
	int sm = 0;
	int fl = 0;
	for(auto x : V){
		sm += x.S - x.F + 1;
		if(sm == sz) fl = 1;
		
		if(sm < sz || fl == 1){
			V2.pb(x);
			continue;
		}
		if(sm > sz){
			int po = x.S - (sm - sz);
			V2.pb({x.F, po});
			V2.pb({po + 1, x.S});
			fl = 1;
		}
	}
	V.swap(V2);
}

void Relax(){
	int sm = 0;
	for(auto x : V) sm += x.S - x.F + 1;
	int po = 1;
	for(auto x : V){
		for(int i = x.F; i <= x.S; i++){
			b[po] = Get(i);
			po ++;
		}
	}

	ch = true;
	for(int i = 1; i <= sm; i++) a[i] = b[i];
	for(int i = sm + 1; i <= n; i++) a[i] = i;
	V = {{1, sm}};
}


ll f[N], iv[N];
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
	V.clear();
	if(ch){
		ch = false;
		iota(a, a + (N / 2), 0);
	}

	cin >> n >> m;
	int la = 0;
	for(int i = 0; i < m; i++){
		cin >> x[i] >> y[i]; 
		if(la + 1 < x[i]){
			V.pb({la + 1, x[i] - 1});
		}
		V.pb({x[i], x[i]});
		la = x[i];
		Break(y[i] - 1);
		int sm = 0;
		for(int j = V.size() - 1; j >= 1; j--){
			sm += V[j - 1].S - V[j - 1].F + 1;
			if(sm <= x[i] - y[i]) swap(V[j], V[j - 1]);
			else break;
		}
		if((i + 1) % Sq == 0) Relax();
	}
	if(x[m - 1] != n) V.pb({x[m - 1] + 1, n});

	// cerr << "!!\n";
	// for(int i = 1; i <= n; i++) cerr << Get(i) << ' ';
	// cerr << '\n';
	// for(auto x : V) cerr << x.F << ' ' << x.S << '\n';
	// cerr << '\n';

	int bd = 0;
	if(!ch){
		for(int i = 0; i + 1 < (int)V.size(); i++){
			if(V[i].S > V[i + 1].F) bd ++;
		}
	} else {
		Relax();
		for(int i = 1; i + 1 <= n; i++)
			if(a[i] > a[i + 1])
				bd ++;
	}
	// debug(bd);

	cout << nCr(n + (n - 1 - bd), (n - 1 - bd) ) << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = mul(f[i - 1], i);
	for(int i = 0; i < N; i++) iv[i] = bin_pow(f[i], Mod - 2);
	// debug(mul(iv[5], f[5]));
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}