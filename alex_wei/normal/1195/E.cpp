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
	int x=0; char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return x;
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

const int N=3e3+5;

int n,m,a,b,h[N][N],hd,tl,d[N],mp[N][N];
ll ans;

int main(){
	cin>>n>>m>>a>>b;
	int g,x,y,z;
	cin>>g>>x>>y>>z;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)h[i][j]=(i<2&&j<2?g:g=(1ll*g*x+y)%z);
	for(int i=1;i<=m;i++){
		hd=1,tl=0;
		for(int j=1;j<=n;j++){
			while(hd<=tl&&d[hd]+a-1<j)hd++;
			while(hd<=tl&&h[d[tl]][i]>=h[j][i])tl--;
			d[++tl]=j,mp[j][i]=h[d[hd]][i];
		}
	}
	for(int i=a;i<=n;i++){
		hd=1,tl=0;
		for(int j=1;j<=m;j++){
			while(hd<=tl&&d[hd]+b-1<j)hd++;
			while(hd<=tl&&mp[i][d[tl]]>=mp[i][j])tl--;
			d[++tl]=j,ans+=(j<b?0:mp[i][d[hd]]);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}