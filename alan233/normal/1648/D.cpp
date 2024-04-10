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

const int N=500005;
const ll inf=1e18;

vector<array<int,3>> event[N];
ll a[4][N],dp[N];
int n,m;

#define ls (u<<1)
#define rs (u<<1|1)
struct DS{
	priority_queue<ll,vector<ll>,greater<ll>> pq1,pq2;
	inline void push(ll x){pq1.push(x);}
	inline void pop(ll x){pq2.push(x);}
	inline bool empty(){
		while(!pq1.empty()&&!pq2.empty()&&pq1.top()==pq2.top())
			pq1.pop(),pq2.pop();
		return pq1.empty();
	}
	inline ll top(){
		while(!pq1.empty()&&!pq2.empty()&&pq1.top()==pq2.top())
			pq1.pop(),pq2.pop();
		return pq1.top();
	}
}tr[N<<2];
ll mx1[N<<3],mx2[N<<3];
void update(int u){
	mx2[u]=max(mx2[ls],mx2[rs]);
	if(!tr[u].empty())ckmax(mx2[u],mx1[u]-tr[u].top());
}
void pushup(int u){
	mx1[u]=max(mx1[ls],mx1[rs]);
	update(u);
}
void update(int u,int l,int r,int pos,ll val){
	if(l==r){
		ckmax(mx1[u],val);
		update(u);
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid)update(ls,l,mid,pos,val);
	else update(rs,mid+1,r,pos,val);
	pushup(u);
}
void push(int u,int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr){
		if(x>0)tr[u].push(x);
		else tr[u].pop(-x);
		update(u);
		return;
	}
	int mid=l+r>>1;
	if(ql<=mid)push(ls,l,mid,ql,qr,x);
	if(qr>mid)push(rs,mid+1,r,ql,qr,x);
	pushup(u);
}

int main(){
	n=read(),m=read();
	rep(i,1,3)
		rep(j,1,n)
			a[i][j]=a[i][j-1]+read();
	rep(i,1,m){
		int l=read(),r=read(),x=read();
		event[l].pb({l-1,n,x});
		event[r+1].pb({l-1,n,-x});
	}
	fill(mx1+1,mx1+(N<<3),-inf);
	fill(mx2+1,mx2+(N<<3),-inf);
	ll ans=-inf;
	rep(i,1,n){
		ll val=a[1][i]-a[2][i-1];
		update(1,0,n,i-1,val);
		for(auto [l,r,x]:event[i])
			push(1,0,n,l,r,x);
		dp[i]=mx2[1];
		update(1,0,n,i,dp[i]);
		ckmax(ans,dp[i]+a[2][i]+a[3][n]-a[3][i-1]);
	}
	print(ans,'\n');
	return 0;
}