#include<bits/stdc++.h>
using namespace std;
const int N=150009;
struct T{
	int a[5],s[5],l,t;
}s[N*4],_;
int o,a[N],u,v,w;
inline void cov(T&k,int x){memset(k.a,0,20),memset(k.s,0,20),k.t=k.a[0]=x,k.s[0]=k.l;}
void mg(T&k,const T&a,const T&b){
	memcpy(k.a,a.a,20),memcpy(k.s,a.s,20);
	int i,j,l,p;
	for(i=0;i<o;++i)if(b.s[i]){
		for(j=0,l=N;j<o;++j){
			if(k.s[j]<l)l=k.s[j],p=j;
			if(k.a[j]==b.a[i]){
				k.s[j]+=b.s[i];
				goto gg;
			}
		}
		if(l<b.s[i]){
			for(j=0;j<o;++j)k.s[j]-=l;
			k.s[p]=b.s[i]-l,k.a[p]=b.a[i];
		}else for(j=0;j<o;++j)k.s[j]-=b.s[i];
		gg:;
	}
}
void bd(int k,int l,int r){
	if(s[k].l=r-l+1,l==r)return cov(s[k],a[l]);
	int m=l+r>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r),mg(s[k],s[k*2],s[k*2+1]);
}
inline void dn(int k){if(s[k].t)cov(s[k*2],s[k].t),cov(s[k*2+1],s[k].t),s[k].t=0;}
void upd(int k,int l,int r){
	if(u<=l&&r<=v)return cov(s[k],w);
	int m=l+r>>1;
	if(dn(k),u<=m)upd(k*2,l,m);
	if(m<v)upd(k*2+1,m+1,r);
	mg(s[k],s[k*2],s[k*2+1]);
}
T qry(int k,int l,int r){
	if(u<=l&&r<=v)return s[k];
	int m=l+r>>1;
	return dn(k),u<=m?(m<v?(mg(_,qry(k*2,l,m),qry(k*2+1,m+1,r)),_):qry(k*2,l,m)):qry(k*2+1,m+1,r);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,m,i;
	cin>>n>>m>>i,o=100/i;
	for(i=1;i<=n;++i)cin>>a[i];
	for(bd(1,1,n);m--;)if(cin>>i>>u>>v,i==1)cin>>w,upd(1,1,n);else{
		for(_=qry(1,1,n),i=0,cout<<o<<' ';i<o;++i)cout<<_.a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}