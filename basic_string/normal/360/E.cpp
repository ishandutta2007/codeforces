#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10105;
priority_queue<pair<ll,int> >q;
int he[N],to[N],ne[N],len[N],L[109],p[109];
bool us[109],f[N];
struct sssp{
	int s;
	ll d[N];
	void dij(){
		int i,j,k;
		ll l;
		memset(f,0,sizeof(f)),memset(d,63,sizeof(d)),d[s]=0,q.push({0,s});
		while(!q.empty()){
			i=q.top().second,q.pop();
			if(f[i])continue;
			f[i]=1;
			for(j=he[i];j;j=ne[j]){
				k=to[j],l=len[j]+d[i];
				if(d[k]>l)d[k]=l,q.push({-l,k});
			}
		}
	}
}A,B;
int main(){
	int n,m,k,t,f,i,j,u,v,w;
	bool b;
	scanf("%d%d%d%d%d%d",&n,&m,&k,&A.s,&B.s,&f);
	for(i=1,j=k+1;i<=m;++i,++j){
		scanf("%d%d%d",&u,&v,&w);
		ne[j]=he[u],to[j]=v,len[j]=w,he[u]=j;
	}
	for(i=1;i<=k;++i){
		scanf("%d%d%d%d",&u,&v,L+i,&w);
		ne[i]=he[u],to[i]=v,len[i]=w,he[u]=i,p[i]=u;
	}
	while(1){
		A.dij(),B.dij(),b=0;
		if(A.d[f]<B.d[f]){
			puts("WIN");
			for(i=1;i<=k;++i)printf("%d ",len[i]);
			return 0;
		}
		for(i=1;i<=k;++i){
			if(!us[i]&&A.d[p[i]]<=B.d[p[i]])us[i]=1,len[i]=L[i],b=1;
		}
		if(!b){
			if(A.d[f]==B.d[f]){
				puts("DRAW");
				for(i=1;i<=k;++i)printf("%d ",len[i]);
			}else puts("LOSE");
			return 0;
		}
	}
	return 0;
}