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

const ll Mod = 1000000007LL;
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

template<typename T>
struct FenwickTree {
	T fen[N];
	FenwickTree (){
		memset(fen, 0, sizeof fen);
	}
	void Add(int idx, T x){
		for(; idx < N; idx += (idx & (-idx)))
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


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	Fenwick cnt;
	Fenwick dl;
	
	ll x;
	ll ans = 0, S = 0;
	for(int i = 0; i < n; i++){
		cin >> x;
		ans += x * i + dl.Get(x);

		ll res = 0;
		for(ll j = 1; j * x < N; j++){
			res += j*(cnt.Get(min(N - 1ll, j * x + x - 1)) - cnt.Get(j*x-1));
		}
		ans += S - res * x;
		
		for(ll j = x; j < N - 1; j += x){
			dl.Add(j, -x);
		}
		cnt.Add(x, 1);
		S += x;
		/////////////////////

		cout << ans << " \n"[i + 1 == n];
	}
	return 0;
}