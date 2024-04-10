#include<bits/stdc++.h>
using namespace std;
const int N=3009;
vector<int>v[N];
#define ll long long
ll f[N],ans[N][N],c[N],mem[27][N];
int n,m,w[N];
void dp(int l,int r){
	for(int i=l;i<=r;++i)for(int j=m;j>=w[i];--j)f[j]=max(f[j],f[j-w[i]]+c[i]);
}
void cdq(int dep,int l,int r){
	if(l==r){
		memcpy(ans[l],f,sizeof(f));
		return;
	}
	int m=l+r>>1;
	memcpy(mem[dep],f,sizeof(f));
	dp(m+1,r),cdq(dep+1,l,m);
	memcpy(f,mem[dep],sizeof(f));
	dp(l,m),cdq(dep+1,m+1,r);
}
int main(){
	int i,j,k,l,o;
	ll w,ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",&k);
		for(j=0;j<k;++j)scanf("%d",&l),v[i].push_back(l);
		k=min(k,m),v[i].resize(k),::w[i]=k;
		w=0;
		for(j=0;j<k;++j)w+=v[i][j];
		c[i]=w;
	}
	cdq(1,1,n);
	for(i=1;i<=n;++i){
		w=0,k=v[i].size();
		for(j=0;j<k;++j){
			w+=v[i][j],ans=max(ans,w+::ans[i][m-j-1]);
		}
	}
	printf("%lld",ans);
	return 0;
}