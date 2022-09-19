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
const int N = 2e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 8;
const ll M = (1 << Log) + 10;


int z[N];

str T;

void Z(){
	memset(z, 0, sizeof z);
	z[0] = 0;
	pll mx = {0, 0};
	ll n = T.size();
	for(int i = 1; i < n; i++){
		if(i <= mx.F){
			z[i] = min(mx.F - i + 1, (ll) z[i - mx.S]);
		}
		while(z[i] + i < n && T[z[i]] == T[i + z[i]]) z[i] ++;
		mx = max(mx, {i + z[i] - 1, i});
	}
	z[0] = n;
}
str rev(str x){
	reverse(all(x));
	return x;
}
int za[N], zb[N];;

template<typename T>
struct FenwickTree {
	T* fen;
	int n;
	FenwickTree (int _n){
		fen = new T[_n + 1];
		n = _n;
		memset(fen, 0, sizeof &fen);
	}
	void Add(int idx, T x){
		for(; idx <= n; idx += (idx & (-idx)))
			fen[idx] += x;
	}
	T Get(int idx){
		T res = 0;
		for(; idx; idx -= (idx & (-idx)))
			res += fen[idx];
		return res;
	}
};
typedef FenwickTree<long long> Fenwick;

Fenwick f1(N), f2(N);

void Add(int i, int f, int d){
	if(f){
	f1.Add(f, d);
	f2.Add(f, d*f);
}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	str a, b, s;
	cin >> a >> b >> s;
	T = s + '#' + a;
	Z();
	for(int i = 0; i < n; i++) za[i] = z[m + 1 + i];
	T = rev(s) + '#' + rev(b);
	Z();
	for(int i = 0; i < n; i++) zb[i] = z[n + m - i];
	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(za[i] == m) za[i] --;
		if(zb[i] == m) zb[i] --;
		
		Add(i, za[i], 1);
		if(i >= m-1) Add(i - (m - 1), za[i - (m - 1)], -1);
		if(zb[i]){
			ll S = f2.Get(N - 1) - f2.Get(max(0ll, m - 1 - zb[i]));
			ll C = f1.Get(N - 1) - f1.Get(max(0ll, m - 1 - zb[i]));
			//debug(i);
			//debug(S);
			//debug(C);
			ans += S + C * (zb[i] - m + 1);
			//debug( S + C * (zb[i] - m + 1));
		}
	}

	cout << ans << '\n';
	return 0;
}