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
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

/*
	Templates end.
	Please give me more points.
*/

const int M=1e4+5;
const int G=1e3+5;
int n,m,g,r,ans=1e9,d[M],vis[M][G];
deque <pii> q;

int main(){
	n=read(),m=read();
	for(int i=0;i<m;i++)d[i]=read();
	g=read(),r=read(),sort(d,d+m);
	q.push_back({0,0});
	while(!q.empty()){
		pii t=q.front(); q.pop_front();
		int p=t.fi,tm=t.se,rr=tm%(g+r);
		if(p){
			int ds=d[p]-d[p-1];
			if(rr+ds<=g&&!vis[p-1][rr+ds]){
				vis[p-1][rr+ds]=1;
				if(rr+ds<g)q.push_front({p-1,tm+ds});
				else q.push_back({p-1,tm+ds+r});
			}
		}
		int ds=d[p+1]-d[p];
		if(rr+ds<=g&&!vis[p+1][rr+ds]){
			if(p==m-2){ans=min(ans,tm+ds); continue;}
			vis[p+1][rr+ds]=1;
			if(rr+ds<g)q.push_front({p+1,tm+ds});
			else q.push_back({p+1,tm+ds+r});
		}
	}
	if(ans<1e9)cout<<ans<<endl;
	else puts("-1");
	return 0;
}