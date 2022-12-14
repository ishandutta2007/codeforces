#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
struct seg{
	#define U(a,b) max(a,b)
	const ll a0=0;
	int n; ll a[1024*1024*4*2];
	void init(int inn){
		for(n=1;n<inn;n<<=1);
		repeat(i,0,n)a[n+i]=a0;
		repeat_back(i,1,n)up(i);
	}
	void up(int x){
		a[x]=U(a[x<<1],a[(x<<1)^1]);
	}
	void update(int x,ll k){
		x+=n; a[x]=max(a[x],k);
		while(x>>=1)up(x);
	}
	ll query(int l,int r){
		ll ans=a0;
		for(l+=n-1,r+=n+1;l^r^1;l>>=1,r>>=1){
			if(~l & 1)ans=U(ans,a[l^1]);
			if(r & 1)ans=U(ans,a[r^1]);
		}
		return ans;
	}
}tr;
map<int,int> mp;
int a[N],nxt[N];
vector<int> pos[N];
void Solve(){
	int n=read(); tr.init(n+3);
	repeat(i,1,n+3)pos[i].push_back(0);
	repeat(i,1,n+1){
		a[i]=read();
		pos[a[i]].push_back(i);
	}
	repeat(i,1,n+3)mp[i]=n+1;
	//orzarr(a+1,n);
	repeat(i,1,n+3)pos[i].push_back(n+1);
	repeat_back(i,1,n+1){
		nxt[i]=mp[a[i]];
		mp[a[i]]=i;
	}
	if(pos[1].size()==2){cout<<2<<endl; return;}
	if((int)pos[1].size()==n+2){cout<<1<<endl; return;} 
	repeat(i,1,n+3){
		//orz(i); orzeach(pos[i]);
		//repeat(i,0,n+1)cout<<tr.query(i,i)<<' '; cout<<endl;
		if(i>1){
			int f=true;
			repeat(j,0,pos[i].size()-1){
				int x=pos[i][j],y=pos[i][j+1];
				//cout<<x<<' '<<y<<endl;
				if(tr.query(0,x)<y){f=false; break;}
			}
			if(f){cout<<i<<endl; return;}
		}
		repeat(j,1,pos[i].size()-1)
			tr.update(pos[i][j],nxt[pos[i][j]]);
		tr.update(0,mp[i]);
	}
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}