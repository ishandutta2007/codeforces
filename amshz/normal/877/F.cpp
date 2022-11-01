# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
const ll md =  998244353;
const int xn = 1e5 + 10;
const int xm = 1e3 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18+ 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, Order[xn], q, ptr = 1;
ll flag[xn], a[xn], part[xn], ans[xn], k, ted, t, S, adj[xn][2], cnt[xn];
map <ll, ll> mp, tab;
vector <pair <ll, int> > vec;
pii Q[xn];

bool cmp(int i, int j){
	if (Q[i].F / SQ != Q[j].F / SQ) return Q[i].F / SQ < Q[j].F / SQ;
	return Q[i].S < Q[j].S;
}

void Solve(int ind){
	ind = max(ind, 1);
	ind --;
	memset(cnt, 0, sizeof cnt);
	ted = 0;
	for (int i = ind; i <= n; i ++){
		ted += cnt[adj[i][0]];
		cnt[part[i]] ++;
		while (ptr <= q && Q[Order[ptr]].F / SQ == (ind + 1) / SQ && Q[Order[ptr]].S == i){
			int j = Order[ptr];
			t = ted;
			for (int p = ind; p < Q[j].F - 1; p ++){
				cnt[part[p]] --;
				t -= cnt[adj[p][1]];
			}
			ans[j] = t;
			for (int p = ind; p < Q[j].F - 1; p ++) cnt[part[p]] ++;
			ptr ++;
		}
	}
}

void Compress(){
	for (int i = 0; i <= n; i ++) vec.push_back({part[i], i});
	sort(vec.begin(), vec.end());
	S = 1;
	for (int i = 0; i <= n; i ++){
		if (i == 0 || vec[i].F != vec[i - 1].F){
			mp[vec[i].F] = S;
			tab[S] = vec[i].F;
			S ++;
		}
		part[vec[i].S] = S - 1;
	}
	for (int i = 0; i <= n; i ++){
		ll x = tab[part[i]];
		adj[i][0] = mp[x - k];
		adj[i][1] = mp[x + k];
	}
}

int main(){
	fast_io;
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> flag[i];
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		part[i] = part[i - 1];
		if (flag[i] == 1) part[i] += a[i];
		else part[i] -= a[i];
	}
	Compress();
	cin >> q;
	for (int i = 1; i <= q; i ++){
		cin >> Q[i].F >> Q[i].S;
		Order[i] = i;
	}
	sort(Order + 1, Order + q + 1, cmp);
	for (int i = 0; i <= n; i += SQ) Solve(i);
	for (int i = 1; i <= q; i ++) cout << ans[i] << endl;
	
	return 0;
}