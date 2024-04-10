#include<bits/stdc++.h>
#define N 500100
#define all(x) begin(x),end(x)
using namespace std;
int a[N];
int mx[N+N];
vector<int> g[N];
void upd_max(int &x,int y){
	if(y>x) x=y;
}
void upd(int l,int r,int n, int v){
	l+=n,r+=n;
	while(l<r){
		if(l&1) upd_max(mx[l++],v);
		if(r&1) upd_max(mx[--r],v);
		l>>=1;
		r>>=1;
	}
}
void mod_seg(int l,int r,int n, int v, int &p){
	l++,r--;
	if(l>r) return;
	upd_max(p,(r-l)/2);
	int m=(l+r+1)/2;
	if(a[l]>=v) upd(l,m,n,v);
	if(a[r]>=v) upd(m,r+1,n,v);
}
void push(int n){
	for(int i=1;i<n;i++){
		upd_max(mx[i<<1],mx[i]);
		upd_max(mx[i<<1|1],mx[i]);
	}
}
int main(){
	int n,p=0;
	scanf("%d",&n);
	set<int> s[2];
	vector<int> v;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	sort(all(v));
	v.resize(unique(all(v))-begin(v));
	for(int i=0;i<n;i++){
		g[lower_bound(all(v),a[i])-begin(v)].push_back(i);
		s[i&1].insert(i);
	}
	for(int j=0;j<2;j++){
		s[j].insert(-1);
		s[j].insert(n);
	}
	for(int i=v.size()-1;i>=0;i--){
		for(int j=0;j<g[i].size();j++){
			int t=g[i][j];
			s[t&1].erase(t);
			s[(t&1)^1].insert(t);
		}
		for(int j=0;j<g[i].size();j++){
			int t=g[i][j],og=t&1;
			int nr=*s[og].upper_bound(t),nl=*(--s[og].lower_bound(t));
			int pr=*s[og^1].upper_bound(t),pl=*(--s[og^1].lower_bound(t));
			mod_seg(nl,nr,n,v[i],p);
			mod_seg(pl,t,n,v[i],p);
			mod_seg(t,pr,n,v[i],p);
		}
	}
	push(n);
	printf("%d\n",p);
	for(int i=n;i<n+n;i++){
		printf("%d ",mx[i]);
	}
	puts("");
	return 0;
}