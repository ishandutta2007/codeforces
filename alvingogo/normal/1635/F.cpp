#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

typedef long long ll;
struct ST{
	struct no{
		ll s,tag;
		no(){
			s=9e18;
			tag=9e18;
		}
	};
	vector<no> st;
	void init(int nn){
		st.resize(4*nn);
	}
	void pup(int v){
		st[v].s=min(st[2*v+1].s,st[2*v+2].s);
	}
	void upd(int v,ll x){
		st[v].s=min(st[v].s,x);
		st[v].tag=min(st[v].tag,x);
	}
	void pudo(int v){
		upd(2*v+1,st[v].tag);
		upd(2*v+2,st[v].tag);
		st[v].tag=9e18;
	}
	void update(int v,int L,int R,int l,int r,ll k){
		if(l==L && r==R){
			upd(v,k);
			return;
		}
		int m=(L+R)/2;
		if(st[v].tag<9e17){
			pudo(v);
		}
		if(r<=m){
			update(2*v+1,L,m,l,r,k);
		}
		else if(l>m){
			update(2*v+2,m+1,R,l,r,k);
		}
		else{
			update(2*v+1,L,m,l,m,k);
			update(2*v+2,m+1,R,m+1,r,k);
		}
		pup(v);
	}
	ll query(int v,int L,int R,int l,int r){
		if(l==L && r==R){
			return st[v].s;
		}
		int m=(L+R)/2;
		if(st[v].tag<8e18){
			pudo(v);
		}
		if(r<=m){
			return query(2*v+1,L,m,l,r);
		}
		else if(l>m){
			return query(2*v+2,m+1,R,l,r);
		}
		else{
			return min(query(2*v+1,L,m,l,m),query(2*v+2,m+1,R,m+1,r));
		}
	}
};
struct qu{
	int l,r,id;
};
bool cmp(qu a,qu b){
	return a.r<b.r;
}
vector<pair<ll,ll> > vp;
ll calc(int x,int y){
	if(x>y){
		swap(x,y);
	}
	return (vp[y].fs-vp[x].fs)*(vp[y].sc+vp[x].sc);
}
int main(){
	AquA;
	int n,q;
	cin >> n >> q;
	vp.resize(n);
	for(int i=0;i<n;i++){
		cin >> vp[i].fs >> vp[i].sc;
	}
	ST st;
	st.init(n);
	deque<int> bg,sm;
	bg.push_back(0);
	sm.push_back(0);
	vector<ll> ans(q);
	vector<qu> vq(q);
	for(int i=0;i<q;i++){
		cin >> vq[i].l >> vq[i].r;
		vq[i].l--;
		vq[i].r--;
		vq[i].id=i;
	}
	sort(vq.begin(),vq.end(),cmp);
	int qt=0;
	for(int i=1;i<n;i++){
		while(sm.size() && vp[sm.back()].sc>vp[i].sc){
			sm.pop_back();
		}
		int l=-1;
		if(sm.size()){
			l=sm.back();
		}
		for(int j=bg.size()-1;j>=0;j--){
			if(l==-1 || vp[bg[j]].fs>=vp[l].fs){
				st.update(0,0,n-1,max(l,0),bg[j],calc(bg[j],i));
			}
			else{
				break;
			}
		}
		while(qt<q && vq[qt].r==i){
			ans[vq[qt].id]=st.query(0,0,n-1,vq[qt].l,i);
			qt++;
		}
		while(bg.size() && vp[bg.back()].sc>vp[i].sc){
			bg.pop_back();
		}
		bg.push_back(i);
		sm.push_back(i);
	}
	for(auto h:ans){
		cout << h << "\n";
	}
	return 0;
}