// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#define repeat(i,a,b) for(int i=(a),ib=(b);i<ib;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,ib=(a);i>=ib;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
// #define int ll
using namespace std;
namespace start{
	typedef long long ll; const int inf=INT_MAX>>1; const ll INF=INT64_MAX>>1;
	typedef double lf; const lf pi=acos(-1.0);
	typedef pair<int,int> pii;
	mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
		ll read(){
			ll x=0,tag=1; char c=getchar(); for(;!isdigit(c);c=getchar())if(c=='-')tag=-1;
			for(;isdigit(c);c=getchar())x=x*10+c-48; // ungetc(c,stdin);
			return x*tag;
		}
		template<typename T> void write(T x){
			if(x<0)x=-x,putchar('-');
			if(x>=10)write(x/10);
			putchar(x%10+48);
		}
		void print(ll x,bool e=0){printf("%lld%c",x," \n"[e]);}
		lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} // will detect EOF
		void printlf(lf x,bool e=0){printf("%.12f%c",x," \n"[e]);}
		template<typename T> vector<T> &operator<<(vector<T> &a,const T &b){a.push_back(b); return a;}
		template<typename T> T sqr(const T &x){return x*x;}
		// int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
		constexpr int bitlog(ll x){return 63-__builtin_clzll(x);} // floor(log2(x))
	const int N=200010;
	const lf eps=1e-9;
	int mod=(1?1000000007:998244353);
		int mul(int a,int b,int m=mod){return 1ll*a*b%m;}
		int qpow(int a,ll b,int m=mod){int ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
}using namespace start;
int Rdeg[N],deg[N];
vector<pii> ans,rec;
vector<int> a[N],b[N];
bool vis[N];
pii trans(pii p){
	if(p.fi>p.se)swap(p.fi,p.se);
	return p;
}
set<pii> st;
void Solve(){
	int n=read();
	repeat(i,1,n+1)a[i].clear(),b[i].clear();
	fill(Rdeg,Rdeg+n+1,0);
	fill(vis,vis+n+1,0);
	ans.clear(); rec.clear(); st.clear();
	repeat(i,0,n-1){
		int x=read(),y=read();
		Rdeg[x]++,Rdeg[y]++;
		a[x].push_back(y);
		a[y].push_back(x);
		st.insert(trans({x,y}));
	}
	queue<int> q;
	repeat(i,1,n+1)if(Rdeg[i]==1)q.push(i);
	fill(deg,deg+n+1,0);
	while(!q.empty()){
		int x=q.front(); q.pop(); vis[x]=1;
		for(auto p:a[x])if(!vis[p]){
			if(deg[x]<=1 && deg[p]<=1){
				deg[x]++,deg[p]++;
				st.erase(trans({x,p}));
				b[x].push_back(p);
				b[p].push_back(x);
			}
			if(--Rdeg[p]==1)q.push(p);
		}
	}
	for(auto i:st)ans.push_back(i);
	fill(vis,vis+n+1,0);
	repeat(i,1,n+1){
		if(!vis[i] && deg[i]<=1){
			int x=i;
			while(1){
				if(b[x].empty()){
					rec.push_back({i,x});
					vis[x]=1;
					break;
				}
				int ch=b[x][0];
				auto it=find(b[ch].begin(),b[ch].end(),x);
				b[ch].erase(it,it+1);
				x=ch;
			}
		}
		else if(deg[i]==0){
			rec.push_back({i,i});
		}
	}
	// orz(ans),orz(rec);
	print(ans.size(),1);
	repeat(i,0,ans.size()){
		printf("%d %d %d %d\n",
			ans[i].fi,ans[i].se,rec[i].se,rec[i+1].fi);
	}
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}