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
	#ifdef __WIN64
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=getchar();
		while(!isdigit(s))sign|=s=='-',s=getchar();
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
		return sign?-x:x;
	}
	void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}
}

// Templates end. Please give me more points.

using namespace IO;

const int N=5e5+5;

int n,m,pd[N];
vector <int> e[N];
struct pos{
	int id,val;
	bool operator < (const pos &v) const {return val<v.val;}
}c[N];

int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){int u=read(),v=read(); e[u].pb(v),e[v].pb(u);}
	for(int i=1;i<=n;i++)c[i].val=read(),c[i].id=i;
	for(int i=1;i<=n;i++){
		map <int,int> mp;
		for(int it:e[i])mp[c[it].val]=1;
		for(int j=1;j<c[i].val;j++)if(!mp[j])puts("-1"),exit(0);
		if(mp[c[i].val])puts("-1"),exit(0);
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)cout<<c[i].id<<" ";
	return 0;
}