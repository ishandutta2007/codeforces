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
vector<ll> cnt[N];
pair<pair<ll, ll>, ll> prs[N];
pair<ll, vector<ll>> t[4*N];
ll recnt[N];
vector<ll> merg(vector<ll> a, vector<ll> b){
	vector<ll> res;
	for(auto i : a) res.pb(i);
	for(auto i : b) res.pb(i);
	return res;
}
pair<ll, vector<ll>> gget(pair<ll, vector<ll>> a, pair<ll, vector<ll>> b){
	if(a.x == b.x){
		return {a.x, merg(a.y, b.y)};
	}else return (a.x < b.x ? a : b);
	//return (a.x == b.x ? (a.y < b.y ? a : b) : (a.x < b.x ? a : b));
}
void build(ll v, ll tl, ll tr){
	if(tl == tr){
		vector<ll> x;
		x.pb(tl);
		t[v] = {cnt[tl].size(), x};
	}else{
		ll tm = (tl+tr)>>1;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v] = gget(t[v*2], t[v*2+1]);
	}
}
bool decrease_or_inf(ll v, ll tl, ll tr, ll pos){
	if(tl == tr && tl  == pos){
		/*if(decr) t[v].x--;
		else t[v].x = val;*/
		t[v].x--;
		if(t[v].x <= 0) {t[v].x = INF; return true;}
		else return false;
	}else{
		ll tm = (tl+tr)>>1;
		//ll rt = 0;
		bool trt = false;
		if(pos >= tl && pos <= tm) trt = decrease_or_inf(v*2, tl, tm, pos);
		else if(pos > tm && pos <= tr) trt = decrease_or_inf(v*2+1, tm+1, tr, pos);
		t[v] = gget(t[v*2], t[v*2+1]);
		return trt;
	}
}
bool is_similar_m(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b){
	ll a1[3] = {a.x.x, a.x.y, a.y};
	ll a2[3] = {b.x.x, b.x.y, b.y};
	ll cc = 0;
	for(ll i = 0;i<3;i++){
		for(ll j = 0;j<3;j++){
			if(a1[i] == a2[j]) cc++;
		}
	}
	return cc >= 2;
}
ll get_free_for(ll a){
	ll xfg = 0;
	while(xfg < cnt[a].size() && prs[cnt[a][xfg]].x.x == INF) xfg++;
	return (xfg >= cnt[a].size() || prs[cnt[a][xfg]].x.x == INF ? -1 : cnt[a][xfg]);
}
int main(){
	FAST;
	ll n;
	cin >> n;
	ll next = 0;
	for(ll i = 0;i<n-2;i++){
		ll a, b, c;
		cin >> a >> b >> c;
		prs[i] = {{a, b}, c};
		cnt[a].pb(i);
		cnt[b].pb(i);
		cnt[c].pb(i);
		recnt[a]++;
		recnt[b]++;
		recnt[c]++;
	}
	for(ll i = 1;i<=n;i++) if(recnt[i]==1) {next=i; break;}
	vector<ll> res;
	for(ll K = 0;K<n-3;K++){
		ll ctx = get_free_for(next);
		if(ctx < 0) break;
		res.pb(next);
		pair<pair<ll, ll>, ll> cache = prs[ctx];
		prs[ctx] = {{INF, INF}, INF};
		if(recnt[cache.x.x] == 2 && is_similar_m(prs[get_free_for(cache.x.x)], cache)) next = cache.x.x;
		if(recnt[cache.x.y] == 2 && is_similar_m(prs[get_free_for(cache.x.y)], cache)) next = cache.x.y;
		if(recnt[cache.y  ] == 2 && is_similar_m(prs[get_free_for(cache.y  )], cache)) next = cache.y  ;
		recnt[cache.x.x]--;
		recnt[cache.x.y]--;
		recnt[cache.y]--;
	}
	/*build(1, 1, n);
	vector<ll> res;
	pair<pair<ll, ll>, ll> last;
	for(ll i = 0;i<n-3;i++){
		if(t[1].x == INF) break;
		/*ll prpos = 0;
		while(prs[cnt[t[1].y][prpos]].x.x == INF) prpos++;
		ll pss = cnt[t[1].y][prpos];
		/*cnt[prs[pss].x.x].erase(find(itr(cnt[prs[pss].x.x]), pss));
		cnt[prs[pss].x.x].erase(find(itr(cnt[prs[pss].x.y]), pss));
		cnt[prs[pss].y  ].erase(find(itr(cnt[prs[pss].y  ]), pss));
		//res.pb(t[1].y);
		if(decrease_or_inf(1, 1, n, prs[pss].x.x)) res.pb(prs[pss].x.x);
		if(decrease_or_inf(1, 1, n, prs[pss].x.y)) res.pb(prs[pss].x.y);
		if(decrease_or_inf(1, 1, n, prs[pss].y)) res.pb(prs[pss].y);
		prs[pss] = {{INF, INF}, INF};
		vector<ll> candidates = t[1].y;
		ll ofxf = 0;
		if(i != 0){
			while(!is_similar_m(get_free_for(candidates[ofxf]), last)) ofxf++;
		}
		ll off = candidates[ofxf];
		ll prpos = 0;
		while(prs[cnt[off][prpos]].x.x == INF) prpos++;
		ll pss = cnt[off][prpos];
		/*cnt[prs[pss].x.x].erase(find(itr(cnt[prs[pss].x.x]), pss));
		cnt[prs[pss].x.x].erase(find(itr(cnt[prs[pss].x.y]), pss));
		cnt[prs[pss].y  ].erase(find(itr(cnt[prs[pss].y  ]), pss));
		//res.pb(t[1].y);
		if(decrease_or_inf(1, 1, n, prs[pss].x.x)) res.pb(prs[pss].x.x);
		if(decrease_or_inf(1, 1, n, prs[pss].x.y)) res.pb(prs[pss].x.y);
		if(decrease_or_inf(1, 1, n, prs[pss].y)) res.pb(prs[pss].y);
		last = prs[pss];
		prs[pss] = {{INF, INF}, INF};
	}*/
	ll prpos = 0;
	while(prs[prpos].x.x == INF) prpos++;
	ll arr[3] = {prs[prpos].x.x, prs[prpos].x.y, prs[prpos].y};
	sort(arr, arr+3, [&](ll aa, ll bb){
		return cnt[aa].size() > cnt[bb].size();
	});
	res.pb(arr[0]);
	res.pb(arr[1]);
	res.pb(arr[2]);
	for(auto i : res) cout << i << " " ;
		cout << endl;
}