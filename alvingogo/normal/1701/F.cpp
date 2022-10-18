#include <bits/stdc++.h>
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
#define int long long
using namespace std;

struct ST{
	struct no{
		int xx=0,x=0,tag=0,z=0;
	};
	vector<no> st;
	void init(int n){
		st.resize(4*n);
	}
	void upd(int v,int k){
		st[v].tag+=k;
		st[v].xx+=2*k*st[v].x+st[v].z*k*k;
		st[v].x+=k*st[v].z;
	}
	void pudo(int v){
		upd(2*v+1,st[v].tag);
		upd(2*v+2,st[v].tag);
		st[v].tag=0;
	}
	void pup(int v){
		st[v].xx=st[2*v+1].xx+st[2*v+2].xx;
		st[v].x=st[2*v+1].x+st[2*v+2].x;
		st[v].z=st[2*v+1].z+st[2*v+2].z;
	}
	void update(int v,int L,int R,int l,int r,int k){
		if(l==L && r==R){
			upd(v,k);
			return;
		}
		pudo(v);
		int m=(L+R)/2;
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
	void update2(int v,int L,int R,int p,int k){
		if(L==R){
			st[v].z=k;
			st[v].xx=k*st[v].tag*st[v].tag;
			st[v].x=k*st[v].tag;
			return;
		}
		pudo(v);
		int m=(L+R)/2;
		if(p<=m){
			update2(2*v+1,L,m,p,k);
		}
		else{
			update2(2*v+2,m+1,R,p,k);
		}
		pup(v);
	}
	int query(){
		return (st[0].xx-st[0].x)/2;
	}
}st;
signed main(){
	AquA;
	int q,d;
	cin >> q >> d;
	const int m=2e5;
	st.init(m);
	vector<int> v(m);
	for(int i=0;i<q;i++){
		int a;
		cin >> a;
		a--;
		if(v[a]){
			v[a]=0;
			if(a){
				st.update(0,0,m-1,max(a-d,0ll),a-1,-1);
			}
			st.update2(0,0,m-1,a,0);
		}
		else{
			v[a]=1;
			if(a){
				st.update(0,0,m-1,max(a-d,0ll),a-1,1);
			}
			st.update2(0,0,m-1,a,1);
		}
		cout << st.query() << "\n";
	}
	return 0;
}