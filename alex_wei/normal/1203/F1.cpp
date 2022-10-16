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

struct node{
	int a,b;
	bool operator < (const node &v) const {
		if((b>=0)!=(v.b>=0))return b>=0;
		if(b>=0)return a<v.a;
		else return a+b>v.a+v.b;
	}
}c[N];
int n,r;

int main(){
	cin>>n>>r;
	for(int i=1;i<=n;i++)cin>>c[i].a>>c[i].b;
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		if(r<c[i].a)puts("NO"),exit(0);
		r+=c[i].b;
	}
	puts(r<0?"NO":"YES");
	
	return 0;
}