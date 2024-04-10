/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//#define int long long

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define vint vector <int>
#define vpii vector <pii>
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

// Templates start.

namespace IO{
	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}
}

namespace math{
	const int mod=99824353;
	const int maxn=1e6+5;

	ll ksm(ll a,ll b){ll s=1,m=a; while(b){if(b&1)s=s*m%mod; m=m*m%mod,b>>=1;} return s;}
	ll inv(ll x){return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n){
		fc[0]=1; for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]); for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	}
	ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

// Templates end. Please give me more points.

using namespace IO;
//using namespace math;

const int N=3e5+25;
const int K=20;

struct ACAM{
	int cnt,son[N][26],ch[N][26],f[N],val[N],tag[N];
	void ins(string s,int rt){
		int p=rt;
		for(char it:s){
			if(!ch[p][it-'a'])ch[p][it-'a']=++cnt;
			p=ch[p][it-'a'];
		} tag[p]++;
	}
	void build(int rt){
		queue <int> q; f[rt]=rt;
		for(int i=0;i<26;i++)
			if(ch[rt][i])f[son[rt][i]=ch[rt][i]]=rt,q.push(son[rt][i]);
			else son[rt][i]=rt;
		while(!q.empty()){
			int t=q.front(); q.pop();
			for(int i=0;i<26;i++)
				if(ch[t][i])f[son[t][i]=ch[t][i]]=son[f[t]][i],q.push(son[t][i]);
				else son[t][i]=son[f[t]][i]; 
			val[t]=tag[t]+val[f[t]];
		}
	}
	ll cal(string s,int rt){
		ll p=rt,ans=0;
		for(char it:s)ans+=val[p=son[p][it-'a']];
		return ans;
	}
	int merge(int x,int y){
		if(!x||!y)return x^y;
		tag[x]+=tag[y];
		for(int i=0;i<26;i++)ch[x][i]=merge(ch[x][i],ch[y][i]);
		return x; 
	}
	int top,sz[K],rt[K];
	void ins(string s){
		ins(s,rt[++top]=++cnt),sz[top]=1;
		while(top&&sz[top]==sz[top-1])
			rt[top-1]=merge(rt[top-1],rt[top]),sz[--top]<<=1;
		build(rt[top]);
	}
	ll cal(string s){
		ll ans=0;
		for(int i=0;i<=top;i++)ans+=cal(s,rt[i]);
		return ans;
	}
	
}a,b;

int m,t;
string s;
int main(){
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>t>>s;
		if(t==1)a.ins(s);
		if(t==2)b.ins(s);
		if(t==3)cout<<a.cal(s)-b.cal(s)<<endl;
	}
	return flush(),0;
}
/*
5
1 a
1 aa
1 aa
1 aaa
3 aaaaa
16
*/