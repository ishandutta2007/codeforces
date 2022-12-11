#include<bits/stdc++.h>
#define N 300000
#define ll long long
using namespace std;
int n,L;
int a[N+1],b[4*N+1],nxt[4*N+1],ls[N+1],bq[4*N+1],p,q,pb;
int fl[N+1],sz[N+1],msz[N+1],pd,pg,p0;
int fwk[N+1];
ll W,ans;
vector<int>ve[N+1];
struct dot{int x;ll y;const bool operator <(dot y)const{if(this->x==y.x)return this->y<y.y;return this->x<y.x;};}d[N+1],g[N+1];
struct que{ll x;int y,ty;const bool operator <(que y)const{if(this->x==y.x)return this->ty*2*N+this->y<y.ty*2*N+y.y;return this->x<y.x;};}q0[N+1];
int qread(){int nans=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=getchar();return nans;}
void lb(int np,int nq,int nr){ls[np]=(a[np]?nxt[ls[np]]:a[np])=++pb,b[pb]=nq,bq[pb]=nr;}
int lowbit(int x){return x&(-x);}
void fwkadd(int np,int nx,int len){for(int i=np;i<=len;i+=lowbit(i))fwk[i]+=nx;}
int fwkreq(int np){int nans=0;for(int i=np;i>=1;i-=lowbit(i))nans+=fwk[i];return nans;}
void putin(){
	n=qread(),L=qread(),W=qread();
	for(int i=2;i<=n;i++)p=qread(),q=qread(),lb(i,p,q),lb(p,i,q);
}
void dfs0(int x){
	fl[x]=sz[x]=1;msz[x]=0;
	for(int i=a[x];i;i=nxt[i])if(!fl[b[i]])dfs0(b[i]),sz[x]+=sz[b[i]],msz[x]=max(msz[x],sz[b[i]]);
	fl[x]=0;
}
int dfs1(int x,int nrt,int nl,int nw){
	fl[x]=1,msz[x]=max(msz[x],sz[nrt]-sz[x]);int nans=x;
//	if(nl<=L&&nw<=W)
	d[++pd]=(dot){nl,nw};
	for(int i=a[x];i;i=nxt[i])if(!fl[b[i]]){int nt=dfs1(b[i],nrt,nl+1,nw+bq[i]);if(msz[nt]<msz[nans])nans=nt;}
	fl[x]=0;return nans;
}
ll cal0(){
	if(!p0)return 0;ll nans=0;
	int st=1;while(q0[st].ty==2&&st<=p0)st++;
	int len=0,mi=4*N;for(int i=st;i<=p0;i++)len=max(len,q0[i].y),mi=min(mi,q0[i].y);len=len-mi+1;
	memset(fwk,0,(len+1)*sizeof(len));
	for(int i=st;i<=p0;i++){
		if(q0[i].ty==1)fwkadd(q0[i].y-mi+1,1,len);
		else nans+=fwkreq(q0[i].y-mi+1);
	}return nans;
}
void ddiv(int x){
	fl[x]=2;
	pg=0;
	for(int i=a[x];i;i=nxt[i]){
		if(fl[b[i]])continue;
		dfs0(b[i]);pd=p0=0;
		int ni=dfs1(b[i],b[i],1,bq[i]);
		ve[x].push_back(ni);
		ll nans=0;
		for(int i=1;i<=pd;i++)q0[++p0]=(que){d[i].y,d[i].x,1},q0[++p0]=(que){W-d[i].y,L-d[i].x,2},nans-=(2*d[i].x<=L&&2*d[i].y<=W);
		sort(q0+1,q0+p0+1);
		nans+=cal0(),ans-=nans/2;
		for(int i=1;i<=pd;i++)g[++pg]=d[i];
	}
	p0=0;ll nans=0;
	for(int i=1;i<=pg;i++)ans+=(g[i].x<=L&&g[i].y<=W),q0[++p0]=(que){g[i].y,g[i].x,1},q0[++p0]=(que){W-g[i].y,L-g[i].x,2},nans-=(2*g[i].x<=L&&2*g[i].y<=W);
	sort(q0+1,q0+p0+1);
	nans+=cal0(),ans+=nans/2;
	for(int i=0;i<ve[x].size();i++)ddiv(ve[x][i]);
	fl[x]=0;
}
signed main(){
	putin();
	ddiv(1);
	cout<<ans<<endl;
	return 0;
}