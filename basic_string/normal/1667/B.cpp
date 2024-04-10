#include<bits/stdc++.h>
using namespace std;
using ll=long long;
enum{N=500009};
ll s[N],w[N];
int m,ans,t0[N*4],t1[N],t2[N*4],u,v,x;
void bd(int k,int l,int r){
	t0[k]=t2[k]=-1e9;
	if(l==r)return;
	int m=l+r>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r);
}
void upd(int k,int l,int r){
	if(l==r){t0[k]=max(t0[k],v-x),t2[k]=max(t2[k],v+x);return;}
	int m=l+r>>1;
	if(u<=m)upd(k*2,l,m);else upd(k*2+1,m+1,r);
	t0[k]=max(t0[k*2],t0[k*2+1]),t2[k]=max(t2[k*2],t2[k*2+1]);
}
void upd(){upd(1,1,m);t1[u]=max(t1[u],v);}
int qry(int k,int l,int r){
	if(u<=l&&r<=v)return t0[k];
	int m=l+r>>1,z=0;
	if(u<=m)z=qry(k*2,l,m);
	if(m<v)z=max(z,qry(k*2+1,m+1,r));
	return z;
}
int qry2(int k,int l,int r){
	if(u<=l&&r<=v)return t2[k];
	int m=l+r>>1,z=0;
	if(u<=m)z=qry2(k*2,l,m);
	if(m<v)z=max(z,qry2(k*2+1,m+1,r));
	return z;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	cin>>T;
	while(T--){
		cin>>n;m=0;s[0]=0;
		for(i=1;i<=n;++i)cin>>s[i],s[i]+=s[i-1];
		w[++m]=0;
		for(i=1;i<=n;++i)w[++m]=s[i];
		sort(w+1,w+m+1);
		m=unique(w+1,w+m+1)-w-1;
		for(i=0;i<=n;++i)s[i]=lower_bound(w+1,w+m+1,s[i])-w;
		bd(1,1,m);
		for(i=1;i<=m;++i)t1[i]=-1e9;
		u=s[0],v=0,x=0,upd();
		for(i=1;i<=n;++i){ 
			k=t1[s[i]];
			if(u=1,v=s[i]-1,u<=v)
			k=max(k,qry(1,1,m)+i);
			if(u=s[i]+1,v=m,u<=v)k=max(k,qry2(1,1,m)-i);
			u=s[i],v=k,x=i,upd();
		}
		cout<<v<<'\n';
	}
}
/*
w-j+i
w
w+j-i
*/