#include<bits/stdc++.h>
#define int long long
#define mid (l+r)/2
#define N 200000
#define inf 99999999999999999
using namespace std;
int n,Q,q0,q1,q2,q3,q4,pa;
int st,a[10*N+1],b[30*N+1],nxt[30*N+1],bq[30*N+1],ls[10*N+1],pb;
int son[10*N+1][2],s[10*N],fl[10*N];
priority_queue<pair<int,int> > pq;
int qread(){int nans=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=getchar();return nans;}
void lb(int np,int nq,int nr){ls[np]=(a[np]?nxt[ls[np]]:a[np])=++pb,b[pb]=nq,bq[pb]=nr;}
void segbuild(int u,int l,int r,int nfl){
	if(l==r){
		if(!nfl)lb(u,l,0);
		else lb(l,u,0);
	}else{
		son[u][0]=++pa,son[u][1]=++pa;
		if(!nfl)lb(u,son[u][0],0),lb(u,son[u][1],0);
		else lb(son[u][0],u,0),lb(son[u][1],u,0);
		segbuild(son[u][0],l,mid,nfl),segbuild(son[u][1],mid+1,r,nfl);
	}
}
void segadd(int u,int l,int r,int nl,int nr,int nx,int nd,int nfl){
	if(l>nr||r<nl)return;
	else if(l>=nl&&r<=nr){
		if(!nfl)lb(nx,u,nd);
		else lb(u,nx,nd);
	}else{
		segadd(son[u][0],l,mid,nl,nr,nx,nd,nfl);
		segadd(son[u][1],mid+1,r,nl,nr,nx,nd,nfl);
	}
}
void putin(){
	n=qread(),Q=qread(),st=qread();
	pa=n+2;
	segbuild(n+1,1,n,0),segbuild(n+2,1,n,1);
	for(int i=1;i<=Q;i++){
		q0=qread(),q1=qread(),q2=qread(),q3=qread();
		if(q0==1)lb(q1,q2,q3);
		else if(q0==2)q4=qread(),segadd(n+1,1,n,q2,q3,q1,q4,0);
		else q4=qread(),segadd(n+2,1,n,q2,q3,q1,q4,1);
	}
}
void dijkstra(){
	for(int i=1;i<=pa;i++)s[i]=inf;s[st]=0;
	pq.push(make_pair(0,st));fl[st]=1;
	while(!pq.empty()){
		int nt=pq.top().second;pq.pop();fl[nt]=0;
		for(int i=a[nt];i;i=nxt[i]){
			if(s[nt]+bq[i]<s[b[i]]){
				s[b[i]]=s[nt]+bq[i];
				if(!fl[b[i]])pq.push(make_pair(-s[b[i]],b[i])),fl[b[i]]=1;
			}
		}
	}
}
signed main(){
//	freopen("running.in","r",stdin);
//	freopen("running.out","w",stdout);
	putin();
	dijkstra();
	for(int i=1;i<=n;i++)cout<<((s[i]>=inf)?-1:s[i])<<' ';cout<<'\n';
	return 0;
}