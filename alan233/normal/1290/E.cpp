// Author: wlzhouzhuan
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

const int N=150005;
const int inf=1e9;

ll ANS[N];
int a[N],b[N],n;

struct SMT{
	#define ls (u<<1)
	#define rs (u<<1|1)
	int mx1[N<<2],mxcnt[N<<2],mx2[N<<2];
	int cnt[N<<2],tag1[N<<2],tag2[N<<2];
	ll sum[N<<2];
	inline void pushup(int u){
		if(mx1[ls]==mx1[rs])
			mx1[u]=mx1[ls],mxcnt[u]=mxcnt[ls]+mxcnt[rs],mx2[u]=max(mx2[ls],mx2[rs]);
		else if(mx1[ls]>mx1[rs])
			mx1[u]=mx1[ls],mxcnt[u]=mxcnt[ls],mx2[u]=max(mx2[ls],mx1[rs]);
		else
			mx1[u]=mx1[rs],mxcnt[u]=mxcnt[rs],mx2[u]=max(mx1[ls],mx2[rs]);
		sum[u]=sum[ls]+sum[rs],cnt[u]=cnt[ls]+cnt[rs];
	}
	inline void pushtag1(int u,int dlt){
		if(cnt[u]&&mx1[u]>dlt){
			sum[u]-=1ll*(mx1[u]-dlt)*mxcnt[u];
			mx1[u]=dlt,tag1[u]=dlt;
		}
	}
	inline void pushtag2(int u,int dlt){
		if(cnt[u]){
			sum[u]+=1ll*cnt[u]*dlt;
			mx1[u]+=dlt,mx2[u]+=dlt,tag1[u]+=dlt,tag2[u]+=dlt;
		}
	}
	inline void pushdown(int u){
		if(tag2[u]){
			pushtag2(ls,tag2[u]),pushtag2(rs,tag2[u]),tag2[u]=0;
		}
		pushtag1(ls,tag1[u]),pushtag1(rs,tag1[u]),tag1[u]=inf;
	}
	void build(int u,int l,int r){
		mx1[u]=mx2[u]=-inf,mxcnt[u]=cnt[u]=sum[u]=0;
		tag1[u]=inf,tag2[u]=0;
		if(l==r)return;
		int mid=l+r>>1;
		build(ls,l,mid),build(rs,mid+1,r);
	}
	void Set(int u,int l,int r,int pos,int dlt){
		if(l==r){
			mx1[u]=sum[u]=dlt,mxcnt[u]=cnt[u]=1;
			return;
		}
		pushdown(u);
		int mid=l+r>>1;
		if(pos<=mid)Set(ls,l,mid,pos,dlt);
		else Set(rs,mid+1,r,pos,dlt);
		pushup(u);
	}
	void updmin(int u,int l,int r,int ql,int qr,int dlt){
		if(ql>qr||mx1[u]<=dlt)return;
		if(ql<=l&&r<=qr&&mx2[u]<dlt)return pushtag1(u,dlt);
		pushdown(u);
		int mid=l+r>>1;
		if(ql<=mid)updmin(ls,l,mid,ql,qr,dlt);
		if(qr>mid)updmin(rs,mid+1,r,ql,qr,dlt);
		pushup(u);
	}
	void updadd(int u,int l,int r,int ql,int qr,int dlt){
		if(ql>qr)return;
		if(ql<=l&&r<=qr)return pushtag2(u,dlt);
		pushdown(u);
		int mid=l+r>>1;
		if(ql<=mid)updadd(ls,l,mid,ql,qr,dlt);
		if(qr>mid)updadd(rs,mid+1,r,ql,qr,dlt);
		pushup(u);
	}
	int qcnt(int u,int l,int r,int ql,int qr){
		if(ql>qr)return 0;
		if(ql<=l&&r<=qr)return cnt[u];
		pushdown(u);
		int mid=l+r>>1,ret=0;
		if(ql<=mid)ret+=qcnt(ls,l,mid,ql,qr);
		if(qr>mid)ret+=qcnt(rs,mid+1,r,ql,qr);
		return ret;
	}
	void dfs(int u,int l,int r){
		if(!cnt[u])return;
		if(l==r){
			printf("R[%d]=%d\n",l,mx1[u]);
			return;
		}
		pushdown(u);
		int mid=l+r>>1;
		dfs(ls,l,mid),dfs(rs,mid+1,r);
	}
}smt;

int main(){
	n=read();rep(i,1,n)a[i]=read(),b[a[i]]=i;
	smt.build(1,1,n);
	rep(i,1,n){
		int pos=b[i];
		smt.updmin(1,1,n,1,pos-1,smt.qcnt(1,1,n,1,pos-1)+1);
		smt.updadd(1,1,n,pos+1,n,1);
		smt.Set(1,1,n,pos,i+1);
		ANS[i]+=smt.sum[1];
		// printf("When i=%d,ans=%lld\n",i,ANS[i]);
		// smt.dfs(1,1,n);
	}
	smt.build(1,1,n);
	rep(i,1,n){
		int pos=b[i];
		smt.updadd(1,1,n,pos+1,n,-1);
		smt.updmin(1,1,n,pos+1,n,-(smt.qcnt(1,1,n,1,pos-1)+1));
		smt.Set(1,1,n,pos,0);
		ANS[i]+=smt.sum[1];
		// printf("When i=%d,ans=%lld\n",i,smt.sum[1]);
		// smt.dfs(1,1,n);
	}
	// \sum R[j]-L[j]-1
	rep(i,1,n)print(ANS[i]-i,'\n');
	return 0;
}