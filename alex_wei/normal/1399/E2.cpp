/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//#define int long long

#define usi unsigned int
#define ll long long
#define pii pair <int,int>
#define pll pair <ll,ll>
#define pdd pair <double,double>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

// Templates start.

namespace IO {
	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline ll read() {
		ll x=0,sign=0; char s=gc;
		while(!isdigit(s)) sign|=s=='-',s=gc;
		while(isdigit(s)) x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	void print(ll x) {if(x>9)print(x/10); pc(x%10+'0');}
}

namespace math {
	const int mod=1e9+7;
	const int maxn=1e6+5;

	ll ksm(ll a,ll b) {ll s=1,m=a; while(b) {if(b&1)s=s*m%mod; m=m*m%mod,b>>=1;} return s;}
	ll inv(ll x) {return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n) {
		fc[0]=1;
		for(int i=1;i<=n;i++) fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]);
		for(int i=n-1;i>=0;i--) ifc[i]=ifc[i+1]*(i+1)%mod;
	}
	ll C(ll n,ll m) {return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}


// Templates end. Please give me more points.

using namespace IO;
//using namespace math;

const int N=1e5+5;

int ccnt,hd[N],nxt[N<<1],vv[N<<1],idd[N<<1];
inline void add(int u,int v,int id){
	nxt[++ccnt]=hd[u],hd[u]=ccnt,vv[ccnt]=v,idd[ccnt]=id;
}

int n; ll s,ss,pre1[N<<5],pre2[N<<5];
struct edge{
	ll cost,val,tim,sub;
	bool operator < (const edge &v) const {
		return sub<v.sub;
	}
}c[N];

int dfs(int id,int f){
	int cnt=0,lf=1;
	for(int i=hd[id];i;i=nxt[i]){
		int to=vv[i];
		if(to!=f)cnt+=c[idd[i]].tim=dfs(to,id),lf=0;
	} return cnt+lf;
}

int main(){
	int t=read();
	while(t--){
		n=read(),s=read(),ccnt=ss=0;
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			add(u,v,i),add(v,u,i);
			c[i].val=read(),c[i].cost=read();
		} dfs(1,0);
		priority_queue <edge> c1,c2;
		for(int i=1;i<n;i++){
			c[i].sub=(c[i].val-(c[i].val>>1))*c[i].tim;
			if(c[i].cost==1)c1.push(c[i]);
			else c2.push(c[i]);
			ss+=c[i].val*c[i].tim;
		}
		int cnt1=0,cnt2=0;
		while(!c1.empty()){
			edge t=c1.top(); c1.pop();
			pre1[cnt1+1]=t.sub+pre1[cnt1];
			cnt1++,t.val>>=1,t.sub=(t.val-(t.val>>1))*t.tim;
			if(t.val)c1.push(t);
		}
		while(!c2.empty()){
			edge t=c2.top(); c2.pop();
			pre2[cnt2+1]=t.sub+pre2[cnt2];
			cnt2++,t.val>>=1,t.sub=(t.val-(t.val>>1))*t.tim;
			if(t.val)c2.push(t);
		} int ans=1e9;
		for(int i=0;i<=cnt1;i++){
			ll res=ss-pre1[i];
			if(res<=s){ans=min(ans,i); break;}
			else{
				int l=0,r=cnt2+1;
				while(l<r){
					int m=l+r>>1;
					if(res-pre2[m]<=s)r=m;
					else l=m+1;
				}
				if(l<=cnt2)ans=min(ans,i+l*2);
			}
		} print(ans),pc('\n'); 
		for(int i=1;i<=ccnt;i++)nxt[i]=0;
		for(int i=1;i<=n;i++)hd[i]=0;
	}
	return flush(),0;
}