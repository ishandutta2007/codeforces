#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 10;

struct node{
	ll a;
	ll ab;
	ll abc;
	ll bc;
	ll c;
	ll b;
	ll lazy;
	void debug(){
		cout << a << " " << ab << " " << abc << " " << bc << " " << c << endl;
		cout << "anddddd " << b << endl;
	}
};
 
node seg[4 * maxn];
 
void propagate(ll, ll, ll);
 
void add(ll id, ll L, ll R, ll l, ll r, ll val){
	if (L == l and R == r){
		seg[id].a += val;
		seg[id].ab -= val;
		seg[id].abc += 0;
		seg[id].bc -= val;
		seg[id].c += val;
		seg[id].b += val;
		seg[id].lazy += val;
		return;
	}
	propagate(id, L, R);
	ll mid = (L + R) >> 1;
	if (l < mid)
		add(2 * id + 0, L, mid, l, min(mid, r), val);
	if (mid < r)
		add(2 * id + 1, mid, R, max(l, mid), r, val);
	
	seg[id].a = max(seg[2 * id + 0].a, seg[2 * id + 1].a);
	seg[id].ab = max(max(seg[2 * id + 0].ab, seg[2 * id + 1].ab), seg[2 * id + 0].a - 2 * seg[2 * id + 1].b);
	seg[id].abc = max(max(seg[2 * id + 0].abc, seg[2 * id + 1].abc),
				max(seg[2 * id + 0].ab + seg[2 * id + 1].c, seg[2 * id + 0].a + seg[2 * id + 1].bc));
	seg[id].bc = max(max(seg[2 * id + 0].bc, seg[2 * id + 1].bc), -2 * seg[2 * id + 0].b + seg[2 * id + 1].c);
	seg[id].c = max(seg[2 * id + 0].c, seg[2 * id + 1].c);
	seg[id].b = min(seg[2 * id + 0].b, seg[2 * id + 1].b);
}
 
void propagate(ll id, ll L, ll R){
	if (seg[id].lazy == 0)
		return;
	ll mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, L, mid, seg[id].lazy);
	add(2 * id + 1, mid, R, mid, R, seg[id].lazy);
	seg[id].lazy = 0;
}

ll c[maxn];
vector<pair<ll,ll> > g[maxn];
ll Time = 1, pos1[maxn], pos2[maxn];

void dfs(ll v, ll p = -1){
	for (auto edge : g[v]){
		ll u = edge.first, idx = edge.second;
		if (u != p){
			pos1[idx] = Time ++;
			dfs(u, v);
			pos2[idx] = Time ++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n, q, w;
	cin >> n >> q >> w;
	for (ll i = 0; i < n - 1; i++){
		ll v, u;
		cin >> v >> u >> c[i];
		v --, u --;
		g[v].push_back({u, i});
		g[u].push_back({v, i});
	}
	dfs(0);
	ll N = 2 * n - 1;
	for (ll i = 0; i < n - 1; i++)
		add(1, 0, N, pos1[i], pos2[i], c[i]);
	ll last = 0;
	for (ll query = 0; query < q; query++){
		ll d, e;
		cin >> d >> e;
		d = (d + last) % (n - 1);
		e = (e + last) % w;
		add(1, 0, N, pos1[d], pos2[d], e - c[d]);
		c[d] = e;
		last = seg[1].abc;
		cout << last << '\n';
	}
}