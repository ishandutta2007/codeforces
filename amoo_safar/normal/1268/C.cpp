#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'
#define int ll

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 4e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

set<ll> st1, st2;
void relax(){
	while(((int) st1.size()) > ((int) st2.size())){
		st2.insert(*st1.rbegin());
		st1.erase(*st1.rbegin());
	}
	while(((int) st2.size()) - ((int) st1.size()) > 1){
		st1.insert(*st2.begin());
		st2.erase(*st2.begin());
	}
}
void ins(ll x){
	if(st2.empty()){
		st1.insert(x);
	} else {
		if(x > (*st2.begin())){
			st2.insert(x);
		} else {
			st1.insert(x);
		}
	}
	relax();
}


ll fen[3][Maxn];
void add(int id, ll idx, ll d){
	for(; idx < Maxn; idx += (idx & -idx)) fen[id][idx] += d;
}
ll get(ll id, ll idx){
	ll res = 0;
	for(; idx; idx -= (idx & -idx)) res += fen[id][idx];
	return res;
}

ll med(){
	return *st2.begin();
}

ll wh[Maxn];
ll C2(ll x){
	return x * (x - 1) / 2LL;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll v;
	for(int i = 1; i <= n; i++){
		cin >> v;
		wh[v] = i;
	}
	ll inv = 0, md;
	for(int i = 1; i <= n; i++){
		ins(wh[i]);
		ll md = med();
		inv += get(0, n) - get(0, wh[i]);
		add(0, wh[i], 1);
		
		add(1, wh[i], wh[i]);
		ll lef = get(1, n) - get(1, md);
		lef -= (((ll) st2.size()) - 1) * md;
		ll rg = -get(1, md - 1);
		rg += (((ll) st1.size())) * md;
		//cerr << md << " " << lef << " " << rg << '\n';
		cout << lef + rg + inv - C2(st2.size()) - C2(st1.size() + 1) << ' ';
		//cerr << "! " << inv << '\n'; 
	}
	
	return 0;
}