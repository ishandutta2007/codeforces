#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200100],b[200100],fa[200100],dep[200100],RT,tr,res,X,Y,Z,A[200100],B[200100];
vector<int>v[200100];
void dfs(int x){for(auto y:v[x])if(y!=fa[x])fa[y]=x,dep[y]=dep[x]+1,dfs(y);}
bool vis[200100],swp[200100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)if(!a[i])tr=i; 
	for(int i=1;i<=n;i++)if(!b[i])RT=i; 
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs(RT);
	while(tr!=RT)swap(a[tr],a[fa[tr]]),swp[tr]=true,tr=fa[tr],res++;
	X=RT;
	for(int i=1;i<=n;i++)if(a[i]!=b[i]&&dep[i]>dep[X])X=i;
	if(X==RT){printf("0 %d\n",res);return 0;}
	Y=X;while(a[Y]!=b[Y])vis[Y]=true,Y=fa[Y];
	for(int x=Y;x!=RT;x=fa[x])if(!swp[x])res+=2;
	Z=RT;for(int i=1;i<=n;i++)if(a[i]!=b[i]&&!vis[i]&&dep[i]>dep[Z])Z=i;
	if(Z==RT){
//		for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
//		for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
		int x,len=dep[X]-dep[Y]+1;
		for(x=X;fa[x]!=Y;x=fa[x])A[a[x]]=a[fa[x]],B[b[x]]=b[fa[x]];
		A[a[x]]=a[X],B[b[x]]=b[X];
		for(int i=1;i<n;i++)if(A[i]!=B[i]){puts("-1");return 0;}
		int num=0;for(int i=a[x];i!=b[x];i=A[i])num++;
		ll A=1ll*num*len,B=1ll*(len-1-num)*len;
		for(x=X;x!=Y;x=fa[x])if(swp[x])B-=2;
		if(X>Y)swap(X,Y);
		printf("%d %d %lld\n",X,Y,min(A,B)+res);
		return 0;
	}
//	printf("%d %d %d\n",X,Y,Z);
	for(int x=Z;x!=Y;x=fa[x])if(a[x]==b[x]){puts("-1");return 0;}else vis[x]=true;
	for(int i=1;i<=n;i++)if(a[i]!=b[i]&&!vis[i]){puts("-1");return 0;}
	int x,z,len=dep[X]+dep[Z]-2*dep[Y]+1;
	for(x=X;fa[x]!=Y;x=fa[x])A[a[x]]=a[fa[x]],B[b[x]]=b[fa[x]];
	for(z=Z;fa[z]!=Y;z=fa[z])A[a[fa[z]]]=a[z],B[b[fa[z]]]=b[z];
	A[a[x]]=a[z],B[b[x]]=b[z];
	A[a[Z]]=a[X],B[b[Z]]=b[X];
	for(int i=1;i<n;i++)if(A[i]!=B[i]){puts("-1");return 0;}
//	for(int i=1;i<n;i++)printf("%d ",A[i]);puts("");
	int num=0;for(int i=a[x];i!=b[x];i=A[i])num++;
	ll A=1ll*num*len,B=1ll*(len-1-num)*len;
	for(x=X;x!=Y;x=fa[x])if(swp[x])B-=2;
	for(z=Z;z!=Y;z=fa[z])if(swp[z])A-=2;
	if(X>Z)swap(X,Z);
	printf("%d %d %lld\n",X,Z,min(A,B)+res);
	return 0;
}