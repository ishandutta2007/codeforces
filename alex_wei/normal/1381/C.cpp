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
	const int mod=998244353;
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

const int N=1e5+5;

int n,x,y,b[N],ori[N],tag[N];

struct node{
	int b,cnt;
	bool operator < (const node &v) const {
		return cnt>v.cnt;
	}
}c[N];

void solve(){
	cin>>n>>x>>y;
	for(int i=1;i<=n+1;i++)ori[i]=tag[i]=0,c[i].b=i,c[i].cnt=0;
	for(int i=1;i<=n;i++)cin>>b[i],c[b[i]].cnt++,ori[b[i]]++;
	
	if(x==n-1&&y==n){
		puts("NO");
		return;
	}
	int disap=0;
	for(int i=1;i<=n+1;i++)if(!c[i].cnt){
		disap=i;
		break;
	}
	sort(c+1,c+n+2);
	if(!c[2].cnt){
		if(x!=y){
			puts("NO");
		}
		else{
			puts("YES");
			for(int i=1;i<=n;i++)
				if(i<=x)cout<<b[i]<<" ";
				else cout<<disap<<" ";
			puts("");
		}
		return;
	}
	
	int v=c[1].cnt-x,rem=n-x;
	if(rem%2==0){
		if(v<=rem/2)puts("YES");
		else{
			if((rem-v<<1)>=y-x)puts("YES");
			else{puts("NO"); return;}
		}
	}
	else{
		if(y==n&&!c[3].cnt){puts("NO"); return;}
		else if(v<=rem/2)puts("YES");
		else if((rem-v<<1)>=y-x)puts("YES");
		else{
			puts("NO");
			return;
		}
	}
	
	vector <pii> d;
	vector <int> tmp(n+1);
	
	int gg=0;
	for(int i=1;i<=n;i++){
		if(ori[b[i]]>rem/2&&gg<x)gg++,ori[b[i]]--;
		else tag[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(tag[i]&&gg<x)gg++,tag[i]=0;
		if(tag[i])d.pb((pii){b[i],i});
	}
	sort(d.begin(),d.end());
	int cont=1,mx=1;
	for(int i=1;i<d.size();i++)
		if(d[i].fi==d[i-1].fi)cont++;
		else mx=max(mx,cont),cont=1;
	mx=max(mx,cont);
	for(int i=0;i<d.size();i++){
		int p=i-mx;
		if(p<0)p+=d.size();
		tmp[i]=d[p].fi;
	}
	int cnt=0;
	for(int i=0;i<d.size();i++)
		if(b[d[i].se]==tmp[i]&&cnt<n-y)
			cnt++,b[d[i].se]=disap,d[i].se=0;
	for(int i=0;i<d.size();i++)
		if(d[i].se){
			if(cnt<n-y)cnt++,b[d[i].se]=disap;
			else b[d[i].se]=tmp[i];
		}
	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
	puts("");
}

int main(){
	int t=1;
	cin>>t;
	while(t--)solve();

	return 0;
}


/*
1
6 3 5
1 1 1 2 2 2
*/