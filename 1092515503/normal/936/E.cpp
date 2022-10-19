/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,q,mx,mn=0x3f3f3f3f,X[300100],Y[300100];
int P[300100],L[300100],R[300100],num[300100],id[300100];
vector<int>v[300100],u[300100];
void ae(int x,int y){/*printf("ae:%d,%d\n",x,y);*/v[x].push_back(y),v[y].push_back(x);}
void AE(int x,int y){/*printf("AE:%d,%d\n",x,y);*/u[x].push_back(y),u[y].push_back(x);}
struct dat{
	int p;mutable int id;dat(int P){p=P;}
	friend bool operator<(const dat&u,const dat&v){return u.p<v.p;}
};
set<dat>s[300100];
int ID(int x,int y){auto it=s[x].find(dat(y));return it!=s[x].end()?it->id:-1;}
vector<int>d[300100],p[300100];
int jum[300100],msz[300100],sz[300100],RT,SZ,dis[300100],pos[300100],tim[300100];
int pre[300100],suf[300100];
inline int lowbit(const int&x){return x&-x;}
inline void chmn(int&x,int y){if(x>y)x=y;}
void PREADD(int x,int pos,int val){val+=pos;for(int i=pos;i>num[x-1];i-=lowbit(i-num[x-1]))chmn(pre[i],val);}
int PREMAX(int x,int pos){int ret=0x3f3f3f3f;for(int i=pos;i<=num[x];i+=lowbit(i-num[x-1]))chmn(ret,pre[i]);return ret-pos;}
void SUFADD(int x,int pos,int val){val-=pos;for(int i=pos;i<=num[x];i+=lowbit(i-num[x-1]))chmn(suf[i],val);}
int SUFMAX(int x,int pos){int ret=0x3f3f3f3f;for(int i=pos;i>num[x-1];i-=lowbit(i-num[x-1]))chmn(ret,suf[i]);return ret+pos;}
bool vis[300100];
void getroot(int x,int fa){
	// printf("getroot:%d,%d\n",x,fa);
	msz[x]=0,sz[x]=1;
	for(auto y:v[x])if(!vis[y]&&y!=fa)getroot(y,x),sz[x]+=sz[y],msz[x]=max(msz[x],sz[y]);
	msz[x]=max(msz[x],SZ-sz[x]);
	if(msz[x]<msz[RT])RT=x;
}
void getsz(int x,int fa){sz[x]=1;for(auto y:v[x])if(!vis[y]&&y!=fa)getsz(y,x),sz[x]+=sz[y];}
queue<int>Q;
void bfs(int x){
	for(int i=num[x-1]+1;i<=num[x];i++)dis[i]=0,pos[i]=i,tim[i]=x,Q.push(i);
	while(!Q.empty()){
		int y=Q.front();Q.pop();
		// printf("%d:%d,%d\n",y,dis[y],pos[y]);
		d[y].push_back(dis[y]),p[y].push_back(pos[y]);
		for(auto z:u[y])if(!vis[id[z]]&&tim[z]!=x)dis[z]=dis[y]+1,pos[z]=pos[y],tim[z]=x,Q.push(z);
	}
}
void solve(int x){
	// printf("solve:%d\n",x);
	bfs(x),getsz(x,0),vis[x]=true;
	for(auto y:v[x])if(!vis[y])RT=0,SZ=sz[y],getroot(y,x),jum[RT]=x,solve(RT);
}
void turnon(int x){
	for(int i=0,y=id[x];i<d[x].size();i++,y=jum[y])
		// printf("%d,%d,%d\n",y,p[x][i],d[x][i]),
		PREADD(y,p[x][i],d[x][i]),SUFADD(y,p[x][i],d[x][i]);
}
int query(int x){
	int res=0x3f3f3f3f;
	for(int i=0,y=id[x];i<d[x].size();i++,y=jum[y])
		// printf("%d,%d,%d\n",y,p[x][i],d[x][i]),
		chmn(res,PREMAX(y,p[x][i])+d[x][i]),chmn(res,SUFMAX(y,p[x][i])+d[x][i]);
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&X[i],&Y[i]),mn=min(mn,X[i]),mx=max(mx,X[i]);
	for(int i=1;i<=n;i++)X[i]=X[i]-mn+1;mx=mx-mn+1;
	for(int i=1;i<=n;i++)s[X[i]].emplace(Y[i]);n=0;
	for(int i=1;i<=mx;i++)for(auto j=s[i].begin();j!=s[i].end();j++){
		P[++m]=i,L[m]=j->p,j->id=++n,id[n]=m;
		while(next(j)!=s[i].end()&&next(j)->p==j->p+1)j++,j->id=++n,id[n]=m;
		R[m]=j->p,num[m]=n;
		// printf("%d[%d,%d]\n",i,L[i],R[i]);
		for(int k=L[m],_;k<=R[m];k++)if((_=ID(i-1,k))!=-1)ae(id[_],m),AE(_,n+k-R[m]);
		for(int k=L[m]+1;k<=R[m];k++)AE(n+k-R[m],n+k-R[m]-1);
	}
	for(int i=1;i<=m;i++)v[i].resize(unique(v[i].begin(),v[i].end())-v[i].begin());
	memset(pre,0x3f,sizeof(pre)),memset(suf,0x3f,sizeof(suf));
	msz[RT=0]=SZ=m,getroot(1,0),solve(RT);
	for(int i=1;i<=n;i++)reverse(p[i].begin(),p[i].end()),reverse(d[i].begin(),d[i].end());
	scanf("%d",&q);
	for(int i=1,tp,x,y,z;i<=q;i++){
		scanf("%d%d%d",&tp,&x,&y),x=x-mn+1,z=ID(x,y);
		// printf("GUGUGU:%d\n",z);
		if(tp==1)turnon(z);else z=query(z),printf("%d\n",z>n?-1:z);
	}
	return 0;
}
/*
7
1 2
1 3
2 3
3 1
3 2
3 3
4 2
3
1 4 2
1 3 3
2 2 3
*/