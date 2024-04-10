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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
const ll Base = 41;

ll lz[N << 2];
pll seg[N << 2];
void Apply(int id, int x){
	seg[id].F += x;
	lz[id] += x;
}
void Shift(int id){
	Apply(id << 1, lz[id]);
	Apply(id << 1 | 1, lz[id]);
	lz[id] = 0;
}
void Build(int id, int L, int R){
	seg[id] = {0, L};
	if(L + 1 == R) return ;
	int mid = (L + R) >> 1;
	Build(id << 1, L, mid);
	Build(id << 1 | 1, mid, R);
}
void Add(int id, int l, int r, int x, int L, int R){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		Apply(id, x);
		return ;
	}
	Shift(id);
	int mid = (L + R) >> 1;
	Add(id << 1, l, r, x, L, mid);
	Add(id << 1 | 1, l, r, x, mid, R);
	seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}
pll Get(int id, int l, int r, int L, int R){
	if(r <= L || R <= l) return {Inf, Inf};
	if(l <= L && R <= r) return seg[id];
	Shift(id);
	int mid = (L + R) >> 1;
	return min(Get(id << 1, l, r, L, mid), Get(id << 1 | 1, l, r, mid, R));
}


ll n, ind[N];
set<ll> st;

void On(ll x){
	//cerr << "? " << x << '\n';
	Add(1, x, n, 1, 0, n);
	if(!st.empty() && (x <= *st.rbegin())){
		int up = *st.lower_bound(x);
		st.erase(up);
		Add(1, up, n, -1, 0, n);
	}
}
void Off(ll x){
	//cerr << "! " << x << '\n';
	Add(1, x, n, -1, 0, n);
	if(seg[1].F < 0){
		int wh = seg[1].S;
		Add(1, wh, n, 1, 0, n);
		st.insert(wh);
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//ll n;
	cin >> n;

	Build(1, 0, n);
	ll v;
	for(int i = 0; i < n; i++){
		cin >> v;
		ind[v] = i;
	}
	ll ans = n;
	On(ind[ans]);
	cout << ans << ' ';
	for(int i = 1; i < n; i++){
		cin >> v;
		v--;
		Off(v);

		while(Get(1, n - 1, n, 0, n).F <= 0){
			ans --;
			On(ind[ans]);
		}
		cout << ans << ' ';
	}

	cin >> v;

	return 0;
}
/*
1
abcdfdcecba

*/