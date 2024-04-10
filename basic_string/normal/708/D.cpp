#include<bits/stdc++.h>
using namespace std;
enum{N=109,M=1999};
int S=N-1,T=N-2,he[N],to[M],len[M],ne[M],cur[N],co[M],t=1,d[N];
queue<int>q;
bool b[N];
bool spfa(){
	int i,j,k,l;
	for(q.push(S),memset(d,63,N*4),d[S]=0;q.size();)for(i=q.front(),q.pop(),b[i]=0,j=he[i];j;j=ne[j])
	if(len[j]&&d[k=to[j]]>(l=d[i]+co[j]))if(d[k]=l,!b[k])b[k]=1,q.push(k);
	return d[T]<1e9;
}
int dfs(int x,int y){
	if(x==T)return y;
	int&i=cur[x],j,u=0,w;
	for(b[x]=1;i;i=ne[i])if(len[i]&&!b[j=to[i]]&&d[j]==d[x]+co[i])
	if(w=dfs(j,min(y-u,len[i])),len[i]-=w,len[i^1]+=w,u+=w,u==y)break;
	return b[x]=0,u;
}
void add(int i,int j,int k=1,int l=0){
	ne[++t]=he[i],to[t]=j,len[t]=k,co[t]=l,he[i]=t;
	ne[++t]=he[j],to[t]=i,co[t]=-l,he[j]=t;
}
int f[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j,k,l,s=0;
	cin>>n>>m;
	while(m--){
		cin>>i>>j>>k>>l;
		if(k<l){
			s+=l-k;
			add(i,j,1e9,2),add(j,i,l-k),add(j,i,k,1);
		}else{
			add(i,j,k-l,1),add(i,j,1e9,2),add(j,i,l,1);
		}
		f[i]+=l,f[j]-=l;
	}
	for(i=1;i<=n;++i)if(f[i]>0)add(i,T,f[i]);else add(S,i,-f[i]);
	add(n,1,1e9);
	while(spfa())memcpy(cur,he,N*4),s+=dfs(S,1e9)*d[T];
	cout<<s;
}