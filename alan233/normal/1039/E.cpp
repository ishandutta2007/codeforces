// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<typename T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
	print(x),putchar(ch);
}

const int N=100005;

vector<int> pot[N];
bool ok[N];
int go[N],n,w,Q,B;

int a[N],f[17][N],g[17][N],lg[N];
void build_rmq(){
	lg[1]=0;rep(i,2,n)lg[i]=lg[i>>1]+1;
	rep(j,1,16){
		rep(i,1,n-(1<<j)+1){
			f[j][i]=min(f[j-1][i],f[j-1][i+(1<<j-1)]);
			g[j][i]=max(g[j-1][i],g[j-1][i+(1<<j-1)]);
		}
	}
}
inline int rmq(int l,int r){
	int len=lg[r-l];
	return max(g[len][l],g[len][r-(1<<len)+1])-min(f[len][l],f[len][r-(1<<len)+1]);
}
inline int jump(int x,int LIM){
	int l=x,r=n+1;
	while(l<r){
		int mid=(l+r)/2;
		if(rmq(x,mid)<=LIM)l=mid+1;
		else r=mid;
	}
	return l;
}

struct QQ{
	int x,id;
	friend bool operator < (const QQ&a,const QQ&b){
		return a.x<b.x;
	}
}q[N];
int ANS[N];

int ch[N][2],fa[N],sz[N];
bool Get(int x){
	return ch[fa[x]][1]==x;
}
bool nroot(int x){
	return ch[fa[x]][0]==x||ch[fa[x]][1]==x;
}
void pushup(int u){
	sz[u]=sz[ch[u][0]]+sz[ch[u][1]]+1;
}
void Rotate(int x){
	int y=fa[x],z=fa[y],k=Get(x);
	if(nroot(y))ch[z][Get(y)]=x;fa[x]=z;
	ch[y][k]=ch[x][k^1];if(ch[x][k^1])fa[ch[x][k^1]]=y;
	ch[x][k^1]=y,fa[y]=x;
	pushup(y),pushup(x);
}
void Splay(int x){
	for(;nroot(x);Rotate(x)){
		if(nroot(fa[x]))
			Rotate(Get(fa[x])==Get(x)?fa[x]:x);
	}
}
void access(int x){
	for(int y=0;x;y=x,x=fa[x]){
		Splay(x),ch[x][1]=y,pushup(x);
	}
}
void link(int x,int y){
	access(x),Splay(x);
	fa[x]=y;
}
void cut(int x,int y){
	access(x),Splay(y);
	fa[x]=ch[y][1]=0,pushup(y);
}
int findroot(int x){
	access(x),Splay(x);
	while(ch[x][0])x=ch[x][0];
	Splay(x);
	return x;
}

int main(){
	n=read(),w=read(),Q=read();
	B=0.4*sqrt(n);
	rep(i,1,n+1)sz[i]=1;
	rep(i,1,n){
		a[i]=read();
		go[i]=i+1,link(i,go[i]),ok[i]=0;
		f[0][i]=g[0][i]=a[i];
	}
	build_rmq();
	rep(i,1,Q)q[i].x=w-read(),q[i].id=i;
	sort(q+1,q+Q+1);
	rep(i,1,n)pot[1].pb(i);
	rep(id,1,Q){
		for(auto i:pot[id]){
			cut(i,go[i]);
			while(go[i]<=n&&go[i]<=i+B&&rmq(i,go[i])<=q[id].x)go[i]++;
			if(go[i]<=i+B){
				link(i,go[i]);
				if(go[i]<=n){
					int _=rmq(i,go[i]);
					int pt=lower_bound(q+1,q+Q+1,(QQ){_,0})-q;
					pot[pt].pb(i);
				}
			}else{
				ok[i]=1;
			}
		}
		pot[id].clear(),pot[id].shrink_to_fit();
		int ans=0;
		for(int i=1;i<=n;i=jump(i,q[id].x),ans++){
			if(!ok[i]){
				access(i),Splay(i),ans+=sz[i]-1;
				i=findroot(i);
			}
			if(i>n)break;
		}
		ANS[q[id].id]=ans;
	}
	rep(i,1,Q)print(ANS[i]-1,'\n');
	return 0;
}