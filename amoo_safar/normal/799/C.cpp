// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
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

ll b[N], p[N];
char t[N];

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
			fen[idx] = max(x, fen[idx]);
	}
	T Get(int idx){
		T res = 0;
		for(; idx; idx -= (idx & (-idx)))
			res = max(res, fen[idx]);
		return (res == 0 ? -Inf : res);
	}
};
typedef FenwickTree<long long> Fenwick;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Fenwick C(N), D(N);
	ll n, c, d;
	cin >> n >> c >> d;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		cin >> b[i] >> p[i] >> t[i];
		if(t[i] == 'C'){
			if(p[i] <= c){
				ans = max(ans, C.Get(c - p[i]) + b[i]);
				C.Add(p[i], b[i]);
			}
		} else {
			if(p[i] <= d){
				ans = max(ans, D.Get(d - p[i]) + b[i]);
				D.Add(p[i], b[i]);
			}
		}
	}
	ans = max(ans, C.Get(c) + D.Get(d));
	cout << ans << '\n';
	return 0;
}