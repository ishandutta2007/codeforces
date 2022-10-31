//ulala
//code by 255
#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 2e5+18;
ll a[N];
struct t_obj{
	ll ans;
	ll sz, max_pref, max_suff, fst, lst;
	t_obj() : ans(0), sz(0), max_pref(0), max_suff(0), lst(0), fst(0) {}
	bool neu=1;
};
t_obj t[4*N];
t_obj mix(t_obj a, t_obj b){
	if(a.neu) return b;
	if(b.neu) return a;
	t_obj r;
	r.sz = a.sz+b.sz;
	r.ans = a.ans+b.ans + (a.lst <= b.fst ? a.max_suff * b.max_pref : 0);
	r.fst = a.fst;
	r.lst = b.lst;
	r.max_pref = a.max_pref + (a.max_pref == a.sz && a.lst <= b.fst ? b.max_pref : 0);
	r.max_suff = b.max_suff + (b.max_suff == b.sz && a.lst <= b.fst ? a.max_suff : 0);
	r.neu = false;
	return r;
}
void build(ll v, ll tl, ll tr){
	if(tl==tr){
		t[v].sz=1;
		t[v].ans=1;
		t[v].max_pref = 1;
		t[v].max_suff = 1;
		t[v].fst = a[tl];
		t[v].lst = a[tl];
		t[v].neu = 0;
		return;
	}
	ll tm = (tl+tr)>>1;
	build(v+v, tl, tm);
	build(v+v+1, tm+1, tr);
	t[v]=mix(t[v+v], t[v+v+1]);
}
void upd(ll v, ll tl, ll tr, ll pos){
	if(tl==tr){
		t[v].sz=1;
		t[v].ans=1;
		t[v].max_pref = 1;
		t[v].max_suff = 1;
		t[v].fst = a[tl];
		t[v].lst = a[tl];
		t[v].neu = 0;
		return;
	}
	ll tm = (tl+tr)>>1;
	if(pos<=tm) upd(v+v, tl, tm, pos);
	else upd(v+v+1, tm+1, tr, pos);
	t[v]=mix(t[v+v], t[v+v+1]);
}
t_obj get(ll v, ll tl, ll tr, ll ql, ll qr){
	if(tl>=ql &&tr<=qr){
		return t[v];
	}
	ll tm = (tl+tr)>>1;
	t_obj x;
	x.neu=1;
	if(tl<=qr&&ql<=tm) x=mix(x, get(v+v, tl, tm, ql, qr));
	if(tm+1<=qr&&ql<=tr) x=mix(x, get(v+v+1, tm+1, tr, ql, qr));
	return x;
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, q;
	cin >> n >> q;
	for(ll i = 0;i<n;i++) cin >> a[i];
	build(1, 0, n-1);
	while(q--){
		ll t, x, y;
		cin >> t >> x >> y;
		if(t==1){
			a[x-1]=y;
			upd(1, 0, n-1, x-1);
		}else{
			cout<<get(1, 0, n-1, x-1, y-1).ans<<'\n';
		}
	}
}