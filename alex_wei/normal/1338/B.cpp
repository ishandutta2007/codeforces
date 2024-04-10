/*
	Templates start.
	Powered by c++11.
	Author : Alex_Wei.
*/

//#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

// IO templates.

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

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

/*
	Templates end.
	Please give me more points.
*/

const int N=3e5+5;

int n,l[N],fa[N],ma;
vector <int> e[N],d1[N],d2[N],dep[2];

void dfs(int id,int f,int d){
	fa[id]=f;
	if(l[id])d1[fa[id]].pb(id),d2[fa[fa[id]]].pb(id),dep[d&1].pb(id);
	for(auto it:e[id])if(it!=f)dfs(it,id,d+1);
	if(d1[id].size())ma-=d1[id].size()-1;
}


void solve(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v),e[v].pb(u);
	}
	for(int i=1;i<=n;i++)if(e[i].size()==1)l[i]=1;
	for(int i=1;i<=n;i++)if(e[i].size()>1){
		ma=n-1,dfs(i,0,0);
		cout<<(dep[0].size()&&dep[1].size()?3:1)<<" "<<ma<<endl;
		return;
	}
}

int main(){
	int testcase=1;
//	cin>>testcase;
	while(testcase--)solve();
	
	return 0;
}