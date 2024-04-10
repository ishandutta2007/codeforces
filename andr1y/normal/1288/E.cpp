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
#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL
#define M 1000000007
#define N 300300
#define INF 101111111111111LL
using namespace std;
using python = void;

vector<ll> t[4*N];
vector<ll> empty_set_ae;
ll a[N];
ll mr[N], mxr[N], xbf[N], nxt[N], pnxt[N];

void merge_vector(vector<ll> &t1, vector<ll> &t2, vector<ll> &tv2){
	vector<ll> tv;
	for(ll i =0, j=0;i<t1.size() || j<t2.size();){
		if(i == t1.size()){
			//if(tv.size() == 0 || tv.back() != t2[j]) 
				tv.pb(t2[j]);
			++j;
			continue;
		}
		if(j == t2.size()){
			//if(tv.size() == 0 || tv.back() != t1[i]) 
				tv.pb(t1[i]);
			++i;
			continue;
		}
		if(t1[i] < t2[j]){
			//if(tv.size() == 0 || tv.back() != t1[i]) 
				tv.pb(t1[i]);
			++i;
		}else{
			//if(tv.size() == 0 || tv.back() != t2[j]) 
				tv.pb(t2[j]);
			++j;
		}
	}
	tv2 = tv;
}

void build(ll v, ll tl, ll tr){
	if(tl == tr){
		t[v].pb(nxt[tl]);
		return;
	}
	ll tm = (tl+tr)>>1;
	build(v+v, tl, tm);
	build(v+v+1, tm+1, tr);
	merge_vector(t[v+v], t[v+v+1], t[v]);
}

void update(ll v, ll tl, ll tr, ll pos, ll val){
	if(tl == tr && tl == pos){
		t[v].pb(val);
	}
	if(tl == tr) return;
	ll tm = (tl+tr)>>1;
	if(pos >= tl && pos <= tm) update(v+v, tl, tm, pos, val);
	if(pos >  tm && pos <= tr) update(v+v+1, tm+1, tr, pos, val);
	merge_vector(t[v+v], t[v+v+1], t[v]);
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
	if(tr < l || tl > r) return 0;
	if(l <= tl && r >= tr){
		ll xl = 0, xr = t[v].size()-1;
		while(xr-xl>1){
			ll xm = (xl+xr)>>1;
			if(t[v][xm] > r) xr = xm;
			else xl = xm;
		}
		ll yr = t[v].size();
		for(ll xm = xr;xm>=xl;xm--) if(t[v][xm] > r) yr = xm;
		return t[v].size()-yr;
	}
	ll tm = (tl+tr)>>1;
	ll res = 0;
	if(tm >= l && tl <= r){
		res += get(v+v, tl, tm, l, r);
	} 
	if(tr >= l && tm+1 <= r){
		res += get(v+v+1, tm+1, tr, l, r);
	}
	return res;
}

ll fwt[N], fwo[N];
void fwset(ll p, ll nw, ll delta = 0){
	delta = nw-fwo[p], fwo[p] = nw;
	for(;p<N;p+=p&-p) fwt[p]+=delta;
}
ll fwsum(ll r, ll s =0){
	for(;r>0;r-=r&-r) s+=fwt[r];
	return s;
}

signed main(){
	FAST;
	ll n, m;
	cin >> n >> m;
	for(ll i =1;i<=n;i++) mr[i] = i, mxr[i] = i;
	for(ll i =1;i<=m;i++) {cin >> a[i];mr[a[i]] = 1;}
	for(ll i =1;i<=n;i++) xbf[i] = 0;
	for(ll i =1;i<=n;i++) pnxt[i] = m+1;
	for(ll i =m;i>0;i--){
		nxt[i] = pnxt[a[i]];
		pnxt[a[i]] = i;
	}
	build(1, 1, m);
	for(ll i =1;i<=m;i++){
		ll top = 0;
		if(fwo[a[i]] == 0){
			fwset(a[i], 1);
			top = fwsum(n)-fwsum(a[i]);
		}
		mxr[a[i]] = max<ll>(mxr[a[i]], (top > 0 ? top+a[i] : get(1, 1, m, xbf[a[i]]+1, i)));
		xbf[a[i]] = i;
	}
	for(ll i = 1;i<=n;i++){
		if(fwo[i] == 0){
			mxr[i] = max(mxr[i], i+fwsum(n)-fwsum(i));
		}else mxr[i] = max<ll>(mxr[i], get(1, 1, m, xbf[i]+1, m)+1);
	}
	for(ll i =1;i<=n;i++) cout << mr[i] << " " << mxr[i] << '\n';
}