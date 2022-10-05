#include<bits/stdc++.h>
using namespace std;
enum{N=300009,M=N*4};
int s[M],s2[M],f[N],f2[N],a[N],b[N],u,v,w,w2;
void bd(int k,int l,int r){
	if(s[k]=s2[k]=1e9,l==r)return;
	int m=l+r>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r);
}
void upd(int k,int l,int r){
	if(u<=l&&r<=v){
		if(s[k]>w)s[k]=w,s2[k]=w2;
		return;
	}
	int m=l+r>>1;
	if(u<=m)upd(k*2,l,m);
	if(m<v)upd(k*2+1,m+1,r);
}
void qry(int k,int l,int r){
	if(f[u]>s[k])f[u]=s[k],f2[u]=s2[k];
	if(l==r)return;
	int m=l+r>>1;
	if(u<=m)qry(k*2,l,m);else qry(k*2+1,m+1,r);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j,k;
	cin>>n,bd(1,0,n);
	for(i=1;i<=n;++i)f[i]=f2[i]=1e9;
	for(i=1;i<=n;++i)cin>>a[n-i];
	for(i=1;i<=n;++i)cin>>b[n-i];
	f[0]=0;
	for(i=0;i<n;++i){
		if(i){
			u=i,qry(1,0,n);
		}
		u=i-b[i],v=u+a[u],w=f[i]+1,w2=i,upd(1,0,n);
	}
	vector<int>ans;
	u=n,qry(1,0,n);
	if(f[n]>1e8)cout<<-1;
	else{
		cout<<f[n]<<'\n';
		for(i=n;i;i=f2[i]){
			ans.push_back(i);
		}
		reverse(begin(ans),end(ans));
		for(int o:ans)cout<<n-o<<' ';
	}
	return 0;
}