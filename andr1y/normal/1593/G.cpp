//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 1e6+18;
struct t_obj{
	ll sz=0, cnt[2]={0};
	t_obj(){

	}
	t_obj(char a){
		sz=1;
		if(a=='['||a==']') cnt[0]++;
	}
	t_obj(t_obj a, t_obj b){
		sz=a.sz+b.sz;
		cnt[0]=a.cnt[0];
		cnt[1]=a.cnt[1];
		if(a.sz&1) swap(b.cnt[0], b.cnt[1]);
		cnt[0]+=b.cnt[0];
		cnt[1]+=b.cnt[1];
	}
	void mixeq(t_obj b){
		if(sz&1){
			swap(b.cnt[0], b.cnt[1]);
		}
		cnt[0]+=b.cnt[0];
		cnt[1]+=b.cnt[1];
		sz+=b.sz;
	}
};
t_obj t[4*N];
void build(string &s, ll v, ll tl, ll tr){
	if(tr==tl+1){
		t[v]=t_obj(s[tl]);
		return;
	}
	ll tm = (tl+tr)>>1;
	build(s, v+v, tl, tm);
	build(s, v+v+1, tm, tr);
	t[v]=t_obj(t[v+v], t[v+v+1]);
}
t_obj get(ll v, ll tl, ll tr, ll ql, ll qr){
	if(tl>=ql&&tr<=qr) return t[v];
	ll tm = (tl+tr)>>1;
	t_obj e=t_obj();
	if(ql<tm&&tl<qr) e.mixeq(get(v+v, tl, tm, ql, qr));
	if(ql<tr&&tm<qr) e.mixeq(get(v+v+1, tm, tr, ql, qr));
	return e;
}


signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		string s;
		cin >> s;
		ll n = s.length();
		build(s, 1, 0, n);
		ll q;
		cin >> q;
		for(ll qq=0;qq<q;qq++){
			ll l, r;
			cin >> l >> r;
			t_obj x = get(1, 0, n, l-1, r);
			cout<<abs(x.cnt[0]-x.cnt[1])<<'\n';
		}
	}
}