// vaziat meshki-ghermeze !
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef unsigned long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const int Log = 18;

ll dp[Log][N];
int phi[N];

vector<int> D[N];

ll seg[N << 2];
ll lz[N << 2];
// void Apply(int id, ll x){
// 	seg[id] += x;
// 	lz[id] += x;
// }
// void Shift(int id){
// 	Apply(id << 1, lz[id]);
// 	Apply(id << 1 | 1, lz[id]);
// 	lz[id] = 0;
// }
void Add(int id, int l, int r, ll x, int L, int R){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		seg[id] += x;
		lz[id] += x;
		// Apply(id, x);
		return ;
	}
	int mid = (L + R) >> 1;
	// Shift(id);
	Add(id << 1, l, r, x, L, mid);
	Add(id<<1|1, l, r, x, mid, R);
	seg[id] = lz[id] + min(seg[id << 1], seg[id << 1 | 1]);
}
ll Get(int id, int l, int r, int L, int R){
	if(r <= L || R <= l) return Inf;
	if(l <= L && R <= r) return seg[id];
	int mid = (L + R) >> 1;
	return lz[id] + min( Get(id << 1, l, r, L, mid), Get(id<<1|1, l, r, mid, R) ) ;
}
int lv;
void Build(int id, int L, int R){
	lz[id] = 0;
	if(L + 1 == R){
		seg[id] = dp[lv][L];
		return ;
	}
	int mid = (L + R) >> 1;
	// Shift(id);
	Build(id << 1, L, mid);
	Build(id<<1|1, mid, R);
	seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 1; i < N; i++){
		phi[i] += i;
		for(int j = i + i; j < N; j += i) phi[j] -= phi[i];
		for(int j = i; j < N; j += i) D[j].pb(i);
	}
	memset(dp, 31, sizeof dp);
	dp[0][0] = 0;
	// ll U = 100'000'000'000;
	for(int lg = 1; lg < Log; lg++){
		lv = lg - 1; Build(1, 0, N);
		dp[lg][0] = 0;
		// Add(1, 0, N, -)
		for(int i = 1; i < N; i++){
			for(auto d : D[i]){
				Add(1, 0, d, phi[i / d], 0, N);
				// cerr << "! " << i << ' ' <<  phi[i / d] << '\n';
			}
			dp[lg][i] = Get(1, 0, i, 0, N);
		}
	}
	// debug("Done\n");
	int q = 0;
	cin >> q;
	for(int i = 0; i < q; i++){
		int a, b;
		cin >> a >> b;
		cout << dp[min(b, Log - 1)][a] << '\n';
	}
	return 0;
}
/*
1
3
5 4 3

*/