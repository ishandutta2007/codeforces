/*
	Templates start.
	Powered by c++11.
	Author : Alex_Wei.
*/

#pragma GCC optimize(3)

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

ll x,y,z,r[N],g[N],b[N];

ll cal(ll a,ll b,ll c){return (a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c);}

void solve(){
	ll ans=5e18+5;
	cin>>x>>y>>z;
	for(int i=1;i<=x;i++)cin>>r[i];
	for(int i=1;i<=y;i++)cin>>g[i];
	for(int i=1;i<=z;i++)cin>>b[i];
	sort(r+1,r+x+1),sort(g+1,g+y+1),sort(b+1,b+z+1);
	for(int i=1;i<=x;i++){
		int p1=lower_bound(g+1,g+y+1,r[i])-g;
		int p2=lower_bound(g+1,g+y+1,r[i])-g-1;
		int p3=lower_bound(b+1,b+z+1,r[i])-b;
		int p4=lower_bound(b+1,b+z+1,r[i])-b-1;
		if(p1&&p1<=y&&p3&&p3<=z)ans=min(ans,cal(r[i],g[p1],b[p3]));
		if(p1&&p1<=y&&p4&&p4<=z)ans=min(ans,cal(r[i],g[p1],b[p4]));
		if(p2&&p2<=y&&p3&&p3<=z)ans=min(ans,cal(r[i],g[p2],b[p3]));
		if(p2&&p2<=y&&p4&&p4<=z)ans=min(ans,cal(r[i],g[p2],b[p4]));
	}
	for(int i=1;i<=max(x,z);i++)swap(r[i],b[i]);
	swap(x,z);
	for(int i=1;i<=x;i++){
		int p1=lower_bound(g+1,g+y+1,r[i])-g;
		int p2=lower_bound(g+1,g+y+1,r[i])-g-1;
		int p3=lower_bound(b+1,b+z+1,r[i])-b;
		int p4=lower_bound(b+1,b+z+1,r[i])-b-1;
		if(p1&&p1<=y&&p3&&p3<=z)ans=min(ans,cal(r[i],g[p1],b[p3]));
		if(p1&&p1<=y&&p4&&p4<=z)ans=min(ans,cal(r[i],g[p1],b[p4]));
		if(p2&&p2<=y&&p3&&p3<=z)ans=min(ans,cal(r[i],g[p2],b[p3]));
		if(p2&&p2<=y&&p4&&p4<=z)ans=min(ans,cal(r[i],g[p2],b[p4]));
	}
	for(int i=1;i<=max(x,y);i++)swap(r[i],g[i]);
	swap(x,y);
	for(int i=1;i<=x;i++){
		int p1=lower_bound(g+1,g+y+1,r[i])-g;
		int p2=lower_bound(g+1,g+y+1,r[i])-g-1;
		int p3=lower_bound(b+1,b+z+1,r[i])-b;
		int p4=lower_bound(b+1,b+z+1,r[i])-b-1;
		if(p1&&p1<=y&&p3&&p3<=z)ans=min(ans,cal(r[i],g[p1],b[p3]));
		if(p1&&p1<=y&&p4&&p4<=z)ans=min(ans,cal(r[i],g[p1],b[p4]));
		if(p2&&p2<=y&&p3&&p3<=z)ans=min(ans,cal(r[i],g[p2],b[p3]));
		if(p2&&p2<=y&&p4&&p4<=z)ans=min(ans,cal(r[i],g[p2],b[p4]));
	}
	cout<<ans<<endl;
}

int main(){
	int testcase=1;
	cin>>testcase;
	while(testcase--)solve();
	
	return 0;
}