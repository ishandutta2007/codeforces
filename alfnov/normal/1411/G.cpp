#include<bits/stdc++.h>
#define A 512
#define mod 998244353
using namespace std;
vector<int>g[100005],l[100005];
int deg[100005],sg[100005];
int vist[A];
int a[A][A+5];
void getsg(int x){
	for(auto cu:l[x])vist[cu]=1;
	sg[x]=0;
	while(vist[sg[x]])++sg[x];
	for(auto cu:l[x])vist[cu]=0;
	l[x].clear();
}
void Add(int* x,int a){
	(*x)+=a;
	if((*x)>=mod)(*x)-=mod;
	if((*x)<=-mod)(*x)+=mod;
}
int niyuan(int x){
	int ans=1,y=mod-2;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return ans;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		++deg[u];
		g[v].emplace_back(u);
	}
	deque<int>dq;
	for(int i=1;i<=n;++i)if(!deg[i]){
		sg[i]=0,dq.emplace_back(i);
	}
	while(dq.size()){
		int x=dq.front();
		dq.pop_front();
		for(auto cu:g[x]){
			--deg[cu];
			l[cu].emplace_back(sg[x]);
			if(deg[cu]==0){
				dq.emplace_back(cu);
				getsg(cu);
			}
		}
	}
	int nI=niyuan(n+1);
	for(int i=0;i<A;++i){
		a[i][A]=-nI*(i!=0);
		for(int j=1;j<=n;++j)Add(&a[i][i^sg[j]],nI);
		a[i][i]-=1;
	}
	for(int i=0;i<A;++i){
		int fl=1;
		if(!a[i][i]){
			fl=0;
			for(int j=i+1;j<A;++j)if(a[j][i]){
				for(int k=0;k<=A;++k)swap(a[i][k],a[j][k]);
				fl=1;
				break;
			}
		}
		if(!fl)continue;
		int ny=niyuan(a[i][i]);
		for(int j=0;j<=A;++j)a[i][j]=1ll*a[i][j]*ny%mod;
		for(int j=0;j<A;++j)if(i!=j&&a[j][i]){
			int zz=a[j][i];
			for(int k=0;k<=A;++k){
				a[j][k]=(a[j][k]-1ll*zz*a[i][k])%mod;
			}
		}
	}
	int ans=a[0][A];
	if(ans<0)ans+=mod;
	printf("%d\n",ans);
	return 0;
}