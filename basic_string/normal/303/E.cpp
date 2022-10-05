#include<bits/stdc++.h>
using namespace std;
const int N=83;
int u[N],v[N],w[N*2],o,n,m;
double s[N][N][N],a[9][N][N],h[N][N],ans[N];
void wk(int d,int l,int r){
	auto g=a[d];
	int t2=n-(r-l+1),t=t2,i,j;
	double p;
	if(l==r){
		if(u[l]<=o&&o<v[l]){
			p=(w[o+1]-w[o])*1./(w[v[l]]-w[u[l]]);
			for(i=t;~i;--i)for(j=t-i;~j;--j)s[l][i][j]+=g[i][j]*p;
		}
		return;
	}
	auto f=a[d+1];
	int m=l+r>>1,k;
	memcpy(f,g,N*N*8);
	for(i=m+1;i<=r;++i,++t){
		memset(h,0,N*N*8);
		if(u[i]<=o&&o<v[i]){
			p=(w[o+1]-w[o])*1./(w[v[i]]-w[u[i]]);
			for(j=t;~j;--j)for(k=t-j;~k;--k)h[j][k]+=f[j][k]*p;
		}
		if(u[i]<o){
			p=(w[min(v[i],o)]-w[u[i]])*1./(w[v[i]]-w[u[i]]);
			for(j=t;~j;--j)for(k=t-j;~k;--k)h[j+1][k]+=f[j][k]*p;
		}
		if(o+1<v[i]){
			p=(w[v[i]]-w[max(o+1,u[i])])*1./(w[v[i]]-w[u[i]]);
			for(j=t;~j;--j)for(k=t-j;~k;--k)h[j][k+1]+=f[j][k]*p;
		}
		memcpy(f,h,N*N*8);
	}
	wk(d+1,l,m),memcpy(f,g,N*N*8),t=t2;
	for(i=l;i<=m;++i,++t){
		memset(h,0,N*N*8);
		if(u[i]<=o&&o<v[i]){
			p=(w[o+1]-w[o])*1./(w[v[i]]-w[u[i]]);
			for(j=t;~j;--j)for(k=t-j;~k;--k)h[j][k]+=f[j][k]*p;
		}
		if(u[i]<o){
			p=(w[min(v[i],o)]-w[u[i]])*1./(w[v[i]]-w[u[i]]);
			for(j=t;~j;--j)for(k=t-j;~k;--k)h[j+1][k]+=f[j][k]*p;
		}
		if(o+1<v[i]){
			p=(w[v[i]]-w[max(o+1,u[i])])*1./(w[v[i]]-w[u[i]]);
			for(j=t;~j;--j)for(k=t-j;~k;--k)h[j][k+1]+=f[j][k]*p;
		}
		memcpy(f,h,N*N*8);
	}
	wk(d+1,m+1,r);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,j,k,l;
	double z;
	for(cin>>n,cout<<setprecision(9),i=1;i<=n;++i)cin>>u[i]>>v[i],w[++m]=u[i],w[++m]=v[i];
	for(sort(w+1,w+m+1),m=unique(w+1,w+m+1)-w-1,i=1;i<=n;++i)u[i]=lower_bound(w+1,w+m+1,u[i])-w,v[i]=lower_bound(w+1,w+m+1,v[i])-w;
	for(o=1,a[0][0][0]=1;o<m;++o)wk(0,1,n);
	for(i=1;i<=n;++i,cout<<'\n'){
		memset(ans,0,N*8);
		for(j=n-1;~j;--j)for(k=n-1-j;~k;--k)l=n-1-j-k,z=s[i][j][k]/(l+1),ans[j+1]+=z,ans[j+l+2]-=z;
		for(j=1;j<=n;++j)ans[j]+=ans[j-1],cout<<ans[j]<<' ';
	}
	return 0;
}