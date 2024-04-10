#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 100005
#define INF 101111111111111
using namespace std;
ll n, m, k;
vector<pll> d[N];
priority_queue<pll, vector<pll>, greater<pll>> pq;
ll dist[N];
bool was[N];
void do_multidjk(){
	for(ll i = 1;i<=k;i++) pq.push({0, i});
	while(!pq.empty()){
		pll now = pq.top();
		pq.pop();
		while(!pq.empty() && was[now.y]){
			now = pq.top();
			pq.pop();
		}
		if(was[now.y]){
			break;
		}
		ll v = now.y;
		ll len = now.x;
		dist[v] = len;
		was[v] = 1;
		for(auto i : d[v]) pq.push({len+i.y, i.x});
	}
}

ll access[N];
void xdfs(ll v, ll p, ll test, ll capacity){
	access[v] = test;
	for(auto i : d[v]) if(access[i.x] != test && capacity-dist[v]-i.y >= dist[i.x]) xdfs(i.x, v, test, capacity);
}

vector<pair<pll, ll>> edges;

vector<pll> d2[N];
ll dsup[N];
ll _parent(ll fr){
	return (dsup[fr] == fr ? fr : dsup[fr] = _parent(dsup[fr]));
}
void _union(ll a, ll b){
	a = _parent(a);
	b = _parent(b);
	if(a != b) dsup[b] = a;
}
void buildmst(){
	sort(itr(edges), [](pair<pll, ll> a, pair<pll, ll> b){
		return a.y < b.y;
	});
	for(ll i = 1;i<=n;i++) dsup[i] = i;
	for(auto i : edges){
		ll a = i.x.x, b = i.x.y, w = i.y;
		if(_parent(a) != _parent(b)){
			d2[a].pb({b, w});
			d2[b].pb({a, w});
			_union(a, b);
		}
	}
}

ll bp[N][20];
ll mebp[N][20];
ll tin[N], tout[N], timer=0;
void bindfs(ll v, ll p, ll lastedge){
	bp[v][0] = p;
	mebp[v][0] = lastedge;
	tin[v] = ++timer;
	for(ll L = 1;L<20;L++){
		if(bp[bp[v][L-1]][L-1] > 0){
			bp[v][L] = bp[bp[v][L-1]][L-1];
			mebp[v][L] = max(mebp[v][L-1], mebp[bp[v][L-1]][L-1]);
		}else break;
	}

	for(auto i : d2[v]){
		if(i.x != p) bindfs(i.x, v, i.y);
	}

	tout[v] = ++timer;
}

inline bool upper(ll a, ll b){
	return tin[a] < tin[b] && tout[a] > tout[b];
}
ll uplen(ll from, ll to){
	ll me = 0;
	for(ll L = 19;L>=0;L--){
		if(bp[from][L] > 0 && !upper(bp[from][L], to)) me=max(me, mebp[from][L]), from = bp[from][L];
	}
	return me;
}
pll lca(ll a, ll b){
	if(upper(a, b)) return {a, uplen(b, a)};
	if(upper(b, a)) return {b, uplen(a, b)};
	ll me = 0;
	for(ll L = 19;L>=0;L--){
		if(bp[a][L] > 0 && !upper(bp[a][L], b)) me=max(me, mebp[a][L]), a = bp[a][L];
	}
	return {bp[a][0], max(me, mebp[a][0])};
}
inline ll get_max_edge_on_path(ll a, ll b){
	pll lcaab = lca(a, b);
	pll lcaba = lca(b, a);
	return max(lcaab.y, lcaba.y);
}

int main(){
	FAST;
	cin >> n >> m >> k;
	ll q;
	cin >> q;
	ll sumw = 0;
	for(ll i = 0;i<m;i++){
		ll a, b, w;
		cin >> a >> b >> w;
		d[a].pb({b, w});
		d[b].pb({a, w});
		edges.pb({{a, b}, w});
		sumw+=w;
	}
	do_multidjk();

	for(auto &i : edges){
		i.y += dist[i.x.x]+dist[i.x.y];
	}

	buildmst();

	bindfs(1, 0, 0);

	ll dfstest = 0;
	while(q--){
		ll a, b;
		cin >> a >> b;
		cout << get_max_edge_on_path(a, b) << endl;
		/*ll l = 0, r = sumw*2;
		while(r-l>1){
			dfstest++;
			ll m = (l+r)>>1;
			xdfs(a, -1, dfstest, m);
			if(access[b] == dfstest) r = m;
			else l = m;
		}
		//cout << "deb: " << l << " " << r << endl;
		for(ll tc = l;tc<=r;tc++){
			dfstest++;
			xdfs(a, -1, dfstest, tc);
			if(access[b] == dfstest){
				cout << tc << endl;
				break;
			}
		}*/
	}
}