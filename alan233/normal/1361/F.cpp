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

const int N=400005;
const int M=70000005;

int p[N],n,q;
ll sxd[N],nxd[N],ans;// , 
int ls[N],rs[N],dad[N],root;

namespace N1{
void dfs1(int &u,int l,int r){
	if(l==r){u=l;return;}
	dfs1(ls[u],l,u-n),dfs1(rs[u],u-n+1,r);
	dad[ls[u]]=dad[rs[u]]=u;
}
void build(){
	static int stk[N],top;
	top=0;
	rep(i,n+1,2*n-1){
		p[i]=read();
		while(top&&p[stk[top]]>p[i])ls[i]=stk[top--];
		if(top)rs[stk[top]]=i;
		stk[++top]=i;
	}
	root=stk[1],dfs1(root,1,n);
	// rep(i,1,2*n-1)printf("dad[%d]=%d\n",i,dad[i]);
}
}

struct SMT{
	int ls[M],rs[M],sum[M],tot;
	void update(int &u,int l,int r,int pos,int dlt){
		if(!u)u=++tot;
		if(l==r){sum[u]+=dlt;return;}
		int mid=l+r>>1;
		if(pos<=mid)update(ls[u],l,mid,pos,dlt);
		else update(rs[u],mid+1,r,pos,dlt);
		sum[u]=sum[ls[u]]+sum[rs[u]];
	}
	int query(int u,int l,int r,int ql,int qr){
		if(!u||ql>qr)return 0;
		if(ql<=l&&r<=qr)return sum[u];
		int mid=l+r>>1,ret=0;
		if(ql<=mid)ret+=query(ls[u],l,mid,ql,qr);
		if(qr>mid)ret+=query(rs[u],mid+1,r,ql,qr);
		return ret;
	}
}smt;
int rt[N];

void ins(int u,int x,int dlt){
	smt.update(rt[u],1,n,x,dlt);
	// printf(" >>> ins u=%d,x=%d,dlt=%d\n",u,x,dlt);
	for(int i=dad[u],j=u;i;j=i,i=dad[i]){
		if(j==rs[i]){
			sxd[i]+=dlt*smt.query(rt[ls[i]],1,n,1,x-1);
			int sav=dlt*smt.query(rt[ls[i]],1,n,x+1,n);
			// printf("type1 i=%d,j=%d,sav=%d\n",i,j,sav);
			nxd[i]+=sav,ans+=sav;
			if(nxd[i]>sxd[i]){
				ans-=nxd[i];
				swap(ls[i],rs[i]),swap(nxd[i],sxd[i]);
				ans+=nxd[i];
			}
		}else{
			sxd[i]+=dlt*smt.query(rt[rs[i]],1,n,x+1,n);
			int sav=dlt*smt.query(rt[rs[i]],1,n,1,x-1);
			// printf("type2 i=%d,j=%d,sav=%d\n",i,j,sav);
			nxd[i]+=sav,ans+=sav;
			if(nxd[i]>sxd[i]){
				ans-=nxd[i];
				swap(ls[i],rs[i]),swap(nxd[i],sxd[i]);
				ans+=nxd[i];
			}
		}
		smt.update(rt[i],1,n,x,dlt);
	}
}

int main(){
	n=read();
	rep(i,1,n)p[i]=read();
	N1::build();
	rep(i,1,n){
		ins(i,p[i],1);
		// printf("after i=%d,ans=%lld\n",i,ans);
	}
	q=read();
	while(q--){
		int x=read(),y=read();
		ins(x,p[x],-1),ins(y,p[y],-1);
		swap(p[x],p[y]);
		ins(x,p[x],1),ins(y,p[y],1);
		print(ans,'\n');
	}
	return 0;
}