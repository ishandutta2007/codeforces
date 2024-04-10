#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,head[100100],cnt,sz[100100],msz[100100],RT;
ll dep[100100],sum;
struct node{int to,next,val;}edge[200100];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++;
}
void getroot(int x,int fa){
	sz[x]=1,msz[x]=0;
	for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=fa)
		getroot(y,x),sz[x]+=sz[y],msz[x]=max(msz[x],sz[y]);
	msz[x]=max(msz[x],n-sz[x]);
	if(msz[x]<msz[RT])RT=x;
}
set<pair<int,int> >s;
set<int>t[101000],r;
int in[101000],out[101000],frm[101000];
void getdep(int x,int fa,int srs){
	sum+=(dep[x]<<1);
	sz[x]=1,t[srs].insert(x),frm[x]=srs;
	for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=fa)
		dep[y]=dep[x]+edge[i].val,getdep(y,x,srs),sz[x]+=sz[y]; 
}
void link(int x,int y){
	printf("%d ",y);
	int X=frm[x],Y=frm[y];
	s.erase(make_pair(in[X]+out[X],X)),in[X]--,s.emplace(in[X]+out[X],X);
	s.erase(make_pair(in[Y]+out[Y],Y)),out[Y]--,s.emplace(in[Y]+out[Y],Y);
	t[Y].erase(y),r.erase(y);
	if(!t[Y].empty())r.insert(*t[Y].begin());
}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head));
	for(int i=1,x,y,z;i<n;i++)scanf("%d%d%d",&x,&y,&z),ae(x,y,z);
	msz[RT=0]=n,getroot(1,0);
	for(int i=head[RT],y;i!=-1;i=edge[i].next)
		dep[y=edge[i].to]=edge[i].val,getdep(y,RT,y),
		in[y]=out[y]=sz[y],s.emplace(sz[y]<<1,y),r.insert(*t[y].begin());
	in[RT]=out[RT]=sz[RT]=1,frm[RT]=RT,r.insert(RT);
	printf("%lld\n",sum);
	if(n==1){puts("1");return 0;}
	for(int i=1;i<=n;i++){
		int y;
		if(s.rbegin()->first==n-i+1&&s.rbegin()->second!=frm[i])
			y=*t[s.rbegin()->second].begin();
		else y=*(frm[*r.begin()]==frm[i]&&*r.begin()!=RT?++r.begin():r.begin());
		link(i,y);
	}
	return 0;
}