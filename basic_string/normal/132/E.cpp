#include<bits/stdc++.h>
using namespace std;
const int N=759,M=4009;
int he[N],to[M],ne[M],len[M],cur[N],co[M],S,T,t=1,h[N],d[N],ed[N],pr[N],a[N],ps[29];
queue<int>q;
using pi=pair<int,int>;
basic_string<pi>ans;
bool f[N];
void add(int x,int y,int z,int w=0){
	ne[++t]=he[x],to[t]=y,len[t]=z,co[t]=w,he[x]=t;
	ne[++t]=he[y],to[t]=x,co[t]=-w,he[y]=t;
}
bool spfa(){
	int i,j,k,l;
	memset(d,9,N*4),d[S]=0,f[S]=1,q.push(S);
	while(!q.empty()){
		i=q.front(),q.pop(),f[i]=0;
		for(j=he[i];j;j=ne[j])if(len[j]&&d[k=to[j]]>(l=d[i]+co[j]))if(d[k]=l,!f[k])f[k]=1,q.push(k);
	}
	return d[T]<1e8;
}
int dfs(int x,int y){
	if(x==T)return y;
	int&i=cur[x],j,u=0,w;
	for(f[x]=1;i;i=ne[i])if(len[i]&&!f[j=to[i]]&&d[j]==d[x]+co[i]){
		w=dfs(j,min(len[i],y-u)),len[i]-=w,len[i^1]+=w,u+=w;
		if(u==y)break;
	}
	return f[x]=0,u;
}
int main(){
	int n,m,i,j,s=0;
	scanf("%d%d",&n,&m),S=n*3+3,T=S+1,add(S-2,1,m),add(n*3-2,S-1,m),add(S-1,S-2,1e9),add(n*3,S-1,1);
	for(i=1;i<=n;++i){
		scanf("%d",a+i),add(i*3-2,i*3-1,1,__builtin_popcount(a[i])),--h[i*3-1],++h[i*3];
		for(j=i-1;j;--j)if(a[j]==a[i]){
			pr[i]=j,add(j*3,i*3-1,1),ed[j]=t;
			break;
		}
	}
	for(i=1;i<n;++i)add(i*3-2,i*3+1,m),add(i*3,i*3+1,1);
	for(i=1;i<S;++i)if(h[i]>0)add(S,i,h[i]);else add(i,T,-h[i]);
	while(spfa())memcpy(cur,he,N*4),s+=dfs(S,1e9)*d[T];
	for(i=1;i<=n;++i)if(len[ed[pr[i]]]){
		for(j=0;j<m;++j)if(ps[j]==pr[i])ps[j]=i,ans+=pi{j,-1};
	}else for(j=0;j<m;++j)if(!len[ed[ps[j]]]){
		ps[j]=i,ans+=pi{j,a[i]},ans+=pi{j,-1};
		break;
	}
	cout<<ans.size()<<' '<<s<<'\n';
	for(auto o:ans)if(~o.second)printf("%c=%d\n",char(o.first+'a'),o.second);else printf("print(%c)\n",char(o.first+'a'));
	return 0;
}