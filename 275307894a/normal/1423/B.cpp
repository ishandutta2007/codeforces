#include<bits/stdc++.h>
using namespace std;
int n,m,k,x[100039],y[100039],z[100039],d[100039],cur,l,r,mid,st=0,t,now[100039],nows,ans;
struct yyy{int to,w,z;}tmp;
struct ljb{
	int head,h[100039];
	yyy f[2000039];
	inline void add(int x,int y,int z){
		f[head]=(yyy){y,z,h[x]};
		h[x]=head++;
	}
}s;
queue<int > q;
inline int bfs(){
	while(!q.empty()) q.pop();
	memset(d,0x3f,sizeof(d));
	q.push(st);
	d[st]=0;
	now[st]=s.h[st];
	while(!q.empty()){
		nows=q.front();
		q.pop();
		cur=s.h[nows];
		while(cur!=-1){
			tmp=s.f[cur];
			if(tmp.w&&d[tmp.to]>=1e9) {
				d[tmp.to]=d[nows]+1;now[tmp.to]=s.h[tmp.to];q.push(tmp.to);
				if(tmp.to==t) return 1;
			}
			cur=tmp.z;
		}
	}
	return 0;
}
inline int dfs(int x,int sum){
	if(x==t) return sum;
	int cur=now[x],k,pus=0;
	yyy tmp;
	while(cur!=-1){
		tmp=s.f[cur];
		now[x]=cur;
		if(tmp.w&&d[tmp.to]==d[x]+1){
			k=dfs(tmp.to,min(sum,tmp.w));
			if(!k) d[tmp.to]=1e9;
			s.f[cur].w-=k;
			s.f[cur^1].w+=k;
			sum-=k;
			pus+=k;
		}
		if(!sum) break;
		cur=tmp.z;
	}
	return pus;
}
inline int check(int mid){
	memset(s.h,-1,sizeof(s.h));
	s.head=0;t=2*n+1;
	register int i;
	for(i=1;i<=n;i++)s.add(0,i,1),s.add(i,0,0);
	for(i=1;i<=n;i++) s.add(i+n,t,1),s.add(t,i+n,0);
	for(i=1;i<=m;i++) if(z[i]<=mid) s.add(x[i],y[i]+n,z[i]),s.add(y[i]+n,x[i],0);
	ans=0;
	while(bfs()) ans+=dfs(st,1e8);
	return ans==n?1:0;
}
int main(){
	memset(s.h,-1,sizeof(s.h));
	memset(d,0x3f,sizeof(d));
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)scanf("%d%d%d",&x[i],&y[i],&z[i]);
	l=0;r=1e9+1;
	while(l+1<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	if(r==1e9+1) printf("-1\n");
	else printf("%d\n",r);
}