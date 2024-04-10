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

namespace IO {
  const int SIZE = 1 << 16;
  char ibuf[SIZE]; int iS, iT;
  char obuf[SIZE]; int oT;
  inline char gc() {
    if (iS == iT)
      iS = 0, iT = fread(ibuf, 1, SIZE, stdin);
    return iS == iT ? EOF : ibuf[iS++];
  }
  inline void pc(char c) {
    obuf[oT++] = c;
    if (oT == SIZE)
      fwrite(obuf, 1, SIZE, stdout), oT = 0;
  }
  inline int read() {
    int x = 0, f = 0;
    char c = gc();
    while (!isdigit(c)) f |= c == '-', c = gc();
    while (isdigit(c)) x = 10 * x + c - '0', c = gc();
    return f ? -x : x; 
  }
  inline void print(int64_t x) {
    static char bufn[64];
    int len = 0;
    if (x < 0) x = -x, pc('-');
    while (x >= 10) bufn[len++] = x % 10 + '0', x /= 10;
    bufn[len++] = x + '0';
    while (len--) pc(bufn[len]);
  }
  inline void print(int64_t x, char ch) {
    print(x), pc(ch);
  }
  struct ff {
    ~ff() {
      if (oT)
        fwrite(obuf, 1, oT, stdout);
    }
  } flusher;
}
using namespace IO;

const int N=100005;
const int inf=1e9;

vector<int> adj[N];
int n,root;

struct SMT{
	#define ls (u<<1)
	#define rs (u<<1|1)
	multiset<int> s[N<<2];
	void push(int u,int l,int r,int pos,int x){
		if(x>0)s[u].insert(x);
		else s[u].erase(s[u].find(-x));
		if(l==r)return;
		int mid=l+r>>1;
		if(pos<=mid)push(ls,l,mid,pos,x);
		else push(rs,mid+1,r,pos,x);
	}
	int calc1(int u,int l,int r,int ql,int qr,int aim){
		if(ql<=l&&r<=qr){
			auto it=s[u].lower_bound(aim);
			if(it==s[u].end())return inf;
			else return *it;
		}
		int mid=l+r>>1,ret=inf;
		if(ql<=mid)ckmin(ret,calc1(ls,l,mid,ql,qr,aim));
		if(qr>mid)ckmin(ret,calc1(rs,mid+1,r,ql,qr,aim));
		return ret;
	}
	int calc2(int u,int l,int r,int ql,int qr,int aim){
		if(ql<=l&&r<=qr){
			auto it=s[u].lower_bound(aim);
			if(it==s[u].begin())return -inf;
			else return *prev(it);
		}
		int mid=l+r>>1,ret=-inf;
		if(ql<=mid)ckmax(ret,calc2(ls,l,mid,ql,qr,aim));
		if(qr>mid)ckmax(ret,calc2(rs,mid+1,r,ql,qr,aim));
		return ret;
	}
}smt;

int dfn[N],dtot;
int sz[N],dep[N],heavy[N],light[N];
int ans[N];
set<int> s[N];
void dfs1(int u,int fa){
	dfn[u]=++dtot;
	dep[u]=dep[fa]+1,sz[u]=1;
	int son=0;
	for(auto v:adj[u]){
		if(v==fa)continue;
		dfs1(v,u),sz[u]+=sz[v];
		if(!heavy[u]||sz[v]>sz[heavy[u]])heavy[u]=v;
		if(!light[u]||sz[v]<sz[light[u]])light[u]=v;
		son++;
	}
	ans[u]=max(sz[heavy[u]],n-sz[u]);
	// printf("init ans[%d]=%d\n",u,ans[u]);
	// if(son==1&&!fa){
	// 	assert(0);
	// }
	if(sz[heavy[u]]>=n-sz[u]&&(n-sz[u]||light[u])){ // 
		int v=heavy[u];
		// printf("here u=%d,heavy=%d (sz=%d),light=%d (sz=%d)\n",u,heavy[u],sz[heavy[u]],light[u],sz[light[u]]);
		int oth=min(n-sz[u]?n-sz[u]:inf,sz[light[u]]);
		auto it=s[v].lower_bound((sz[v]-oth)/2);
		if(it!=s[v].end()){
			int res=max(sz[v]-*it,oth+*it);
			ckmax(res,n-sz[u]);
			for(auto it:adj[u])if(it!=fa&&it!=v)ckmax(res,sz[it]);
			ckmin(ans[u],res);
		}
		if(it!=s[v].begin()){
			it=prev(it);
			int res=max(sz[v]-*it,oth+*it);
			ckmax(res,n-sz[u]);
			for(auto it:adj[u])if(it!=fa&&it!=v)ckmax(res,sz[it]);
			ckmin(ans[u],res);
		}
	}
	s[u].insert(sz[u]);
	for(auto v:adj[u]){
		if(v==fa)continue;
		if(SZ(s[u])<SZ(s[v]))swap(s[u],s[v]);
		for(auto it:s[v])s[u].insert(it);
	}
	smt.push(1,1,n,dfn[u],sz[u]);
}
int stk[N],top;
void dfs2(int u,int fa){
	stk[++top]=u;
	smt.push(1,1,n,dfn[u],-sz[u]);
	if(sz[heavy[u]]<=n-sz[u]&&light[u]){
		int oth=sz[light[u]],aim=(n-sz[u]-oth)/2;
		{
			int q1=min(smt.calc1(1,1,n,1,dfn[u]-1,aim),
		               smt.calc1(1,1,n,dfn[u]+sz[u],n,aim));
			int res=max(n-sz[u]-q1,oth+q1);
			for(auto it:adj[u])if(it!=fa)ckmax(res,sz[it]);
			ckmin(ans[u],res);
		}
		{
			int q2=max(smt.calc2(1,1,n,1,dfn[u]-1,aim),
			           smt.calc2(1,1,n,dfn[u]+sz[u],n,aim));
			int res=max(n-sz[u]-q2,oth+q2);
			for(auto it:adj[u])if(it!=fa)ckmax(res,sz[it]);
			ckmin(ans[u],res);
		}
		int l=0,r=top-1;
		while(l<r){
			int mid=l+r+1>>1;
			if(sz[stk[mid]]-sz[u]>=aim)l=mid;
			else r=mid-1;
		}
		if(l>0){
			int emm=sz[stk[l]]-sz[u];
			int res=max(n-sz[u]-emm,oth+emm);
			for(auto it:adj[u])if(it!=fa)ckmax(res,sz[it]);
			ckmin(ans[u],res);
		}
		if(l+1<top){
			int emm=sz[stk[l+1]]-sz[u];
			int res=max(n-sz[u]-emm,oth+emm);
			for(auto it:adj[u])if(it!=fa)ckmax(res,sz[it]);
			ckmin(ans[u],res);
		}
	}
	for(auto v:adj[u]){
		if(v==fa)continue;
		dfs2(v,u);
	}
	top--;
	smt.push(1,1,n,dfn[u],sz[u]);
}

int main(){
	n=read();
	rep(i,1,n){
		int u=read(),v=read();
		if(u>v)swap(u,v);
		if(!u)root=v;
		else adj[u].pb(v),adj[v].pb(u);
	}
	dfs1(root,0);
	dfs2(root,0);
	rep(i,1,n)print(ans[i],'\n');
    fprintf(stderr,"time used=%.10f\n",clock()/1./CLOCKS_PER_SEC);
	return 0;
}

/*
10
0 1 
5 2 
6 2 
3 7 
1 2 
1 3 
1 4 
4 8 
4 9 
5 10
*/