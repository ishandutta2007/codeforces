#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,q[200039],siz[200039],t,ans,d[200039],maxn,tot;
struct yyy{int to,z;}tmp;
struct ljb{
	int head,h[200039];
	yyy f[400039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
inline void dfs(int x,int last){
	yyy tmp;d[x]=d[last]+1;siz[x]=1e9;
	for(int cur=s.h[x];cur;cur=tmp.z){
		tmp=s.f[cur];
		if(tmp.to!=last) q[x]++,dfs(tmp.to,x),siz[x]=min(siz[x],siz[tmp.to]);
	}
	if(!q[x]) {siz[x]=d[x];return;}
	if(q[x]==1||x==1) return;
	int flags=0;
	for(int cur=s.h[x];cur;cur=tmp.z){
		tmp=s.f[cur];
		if(tmp.to!=last){
			if(siz[tmp.to]==siz[x]&&!flags)flags=1;
			else ans=max(ans,siz[tmp.to]-d[x]+1);
		} 
	}
}
int main(){
	//freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&t);
	while(t--){
		for(i=1;i<=n;i++) s.h[i]=0,q[i]=siz[i]=d[i]=0;ans=0;
		scanf("%d",&n);s.head=0;
		for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);
		dfs(1,0);maxn=0;tot=0;
		for(i=s.h[1];i;i=tmp.z){
			tmp=s.f[i];
			if(siz[tmp.to]>maxn) maxn=siz[tmp.to],tot=1;
			else if(siz[tmp.to]==maxn)tot++;
		}
		printf("%d\n",max(ans,maxn-1+(tot==1?0:1)));
	}
}