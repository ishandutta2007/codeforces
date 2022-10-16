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
 
const int N=2e5+5;
 
int n,dis[N],fa[N],tg[N],dep[N],f[N],ans;
vector <int> e[N];
 
int b1(){
	queue <pii> q;
	q.push({1,0});
	while(!q.empty()){
		pii t=q.front(); q.pop();
		dis[t.fi]=dis[t.se]+1;
		for(auto it:e[t.fi])if(it!=t.se)q.push({it,t.fi});
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(dis[i]>dis[ans])ans=i;
	return ans;
}
int b2(int s){
	queue <pii> q;
	memset(dis,0,sizeof(dis));
	q.push({s,0});
	while(!q.empty()){
		pii t=q.front(); q.pop();
		dis[t.fi]=dis[t.se]+1;
		for(auto it:e[t.fi])if(it!=t.se)q.push({it,t.fi});
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(dis[i]>dis[ans])ans=i;
	return ans;
}
 
void d1(int id,int f,int d){
	fa[id]=f,dep[id]=d;
	for(auto it:e[id])if(it!=f)d1(it,id,d+1);
}
void d2(int id,int fr){
	if(!tg[id])f[id]=f[fr]+1;
	for(auto it:e[id])if(it!=fr&&!tg[it])d2(it,id);
	if(f[id]>f[ans])ans=id;
}
 
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v),e[v].pb(u);
	}
	d1(1,0,0);
	int a=b1(),aa=a,b=b2(a),bb=b,len=0;
	if(dep[a]<dep[b])swap(a,b);
	while(dep[a]>dep[b])len++,tg[a]=1,a=fa[a];
	while(a!=b)tg[a]=tg[b]=1,a=fa[a],b=fa[b],len+=2;
	tg[a]=1;
	
	for(int i=1;i<=n;i++)if(tg[i])d2(i,0);
	cout<<f[ans]+len<<endl<<aa<<" "<<bb<<" ";
	if(!ans)for(int i=1;i<=n;i++)if(i!=aa&&i!=bb)cout<<i,exit(0);
	cout<<ans<<endl;
	
	return 0;
}