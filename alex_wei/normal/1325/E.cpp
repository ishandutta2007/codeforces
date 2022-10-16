/*
	Templates start.
	Powered by c++11.
	Author : Alex_Wei.
*/
 
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
 
const int N=1e5+5;
 
vector <int> e[N<<4],ap;
int n,a,dis[N<<4],ans=N;
map <int,bool> mp;
 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		int x=1,y=1;
		for(int j=2;j*j<=a;j++)while(a%(j*j)==0)a/=j*j;
		if(a==1)puts("1"),exit(0);
		for(int j=2;j*j<=a;j++)if(a%j==0){
			if(x==1)x=j;
			else y=j;
			while(a%j==0)a/=j;
		}
		if(a>1)x==1?x=a:y=a;
		e[x].pb(y),e[y].pb(x);
		ap.pb(x),ap.pb(y);
	}
	sort(all(ap)),ap.resize(unique(all(ap))-ap.begin());
	for(auto it:ap)mp[it]=1;
	
	for(int i=1;i*i<=1e6;i++){
		if(mp.find(i)==mp.end())continue;
		for(auto it:ap)dis[it]=0;
		queue <pii> q;
		q.push({i,0}),dis[i]=1;
		while(!q.empty()){
			pii t=q.front(); q.pop();
			for(auto it:e[t.fi]){
				if(it==t.se)continue;
				if(dis[it])ans=min(ans,dis[it]+dis[t.fi]-1);
				else dis[it]=dis[t.fi]+1,q.push({it,t.fi});
			}
		}
	}
	cout<<(ans==N?-1:ans)<<endl;
	
	return 0;
}