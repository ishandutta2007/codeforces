#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

//const ll Mod = 1000000007LL;
ll Mod;
const int Maxn = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

set<ll> st;
map<ll, ll> mp;
ll al[Maxn], ar[Maxn], bl[Maxn], br[Maxn];

vector<ll> s[Maxn], e[Maxn];

ll seg[Maxn << 2];
ll lz[Maxn << 2];
ll apply(ll id, ll x, ll L, ll R){
	seg[id] += x * (R - L);
	lz[id] += x;
}
void shift(ll id, ll L, ll R){
	ll mid = (L + R) >> 1;
	apply(id << 1, lz[id], L, mid);
	apply(id << 1 | 1, lz[id], mid, R);
	lz[id] = 0;
}

void add(ll id, ll l, ll r, ll x, ll L, ll R){
	if((r <= L) || (R <= l)) return ;
	if((l <= L) && (R <= r)){
		apply(id, x, L, R);
		return ;
	}
	shift(id, L, R);
	ll mid = (L + R) >> 1;
	add(id << 1, l, r, x, L, mid);
	add(id << 1|1, l, r, x, mid, R);
seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

ll get(ll id, ll l, ll r, ll L, ll R){
	if((r <= L) || (R <= l)) return 0;
	if((l <= L) && (R <= r)) return seg[id];
	shift(id, L, R);
	ll mid = (L + R) >> 1;
	return get(id << 1, l, r, L, mid) + get(id << 1|1, l, r, mid, R);
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> al[i] >> ar[i]; ar[i] ++;
		cin >> bl[i] >> br[i]; br[i] ++;
		st.insert(al[i]);
		st.insert(ar[i]);
		st.insert(bl[i]);
		st.insert(br[i]);
	}
	ll cnt = 1;
	for(auto x : st) mp[x] = cnt ++;
	
	for(int i = 0; i < n; i++){
		al[i] = mp[al[i]];
		ar[i] = mp[ar[i]];
		bl[i] = mp[bl[i]];
		br[i] = mp[br[i]];
		e[ar[i]].pb(i);
		s[al[i]].pb(i);
	}
	for(int i = 0; i < Maxn; i++){
		for(auto x : e[i]){
			add(1, bl[x], br[x], 1, 1, Maxn);
		}
		
		for(auto x : s[i]){
			if(get(1, bl[x], br[x], 1, Maxn) > 0) return cout << "NO\n",0 ;
		}
	}
	swap(al, bl);
	swap(ar, br);
	for(int i = 0; i < Maxn; i++){
		s[i].clear();
		e[i].clear();
	}
	memset(seg, 0, sizeof seg);
	memset(lz, 0, sizeof lz);
	for(int i = 0; i < n; i++){
		e[ar[i]].pb(i);
		s[al[i]].pb(i);
	}
	for(int i = 0; i < Maxn; i++){
		for(auto x : e[i]){
			add(1, bl[x], br[x], 1, 1, Maxn);
		}
		
		for(auto x : s[i]){
			if(get(1, bl[x], br[x], 1, Maxn) > 0) return cout << "NO\n", 0;
		}
	}
	
	
	cout << "YES\n";
	return 0;

}