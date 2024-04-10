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

struct point{
	int x,y;
	bool operator < (const point &v) const {
		return y==v.y?x<v.x:y>v.y;
	}
}c[N];

int n,p[N],sz;
ll ans;

int val[N<<2];
void modify(int l,int r,int pos,int x){
	if(l==r){
		val[x]=1;
		return;
	}
	int m=l+r>>1;
	if(pos<=m)modify(l,m,pos,x<<1);
	else modify(m+1,r,pos,x<<1|1);
	val[x]=val[x<<1]+val[x<<1|1];
}
int query(int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr)return val[x];
	int m=l+r>>1,ans=0;
	if(ql<=m)ans+=query(l,m,ql,qr,x<<1);
	if(m<qr)ans+=query(m+1,r,ql,qr,x<<1|1);
	return ans;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++)c[i].x=p[i]=read(),c[i].y=read();
	sort(p+1,p+n+1),sz=unique(p+1,p+n+1)-p-1;
	for(int i=1;i<=n;i++)c[i].x=lower_bound(p+1,p+sz+1,c[i].x)-p;
	sort(c+1,c+n+1);
	
	for(int i=1;i<=n;i++){
		modify(1,sz,c[i].x,1);
		ans+=1ll*query(1,sz,1,c[i].x,1)*query(1,sz,c[i].x,(c[i+1].y==c[i].y?c[i+1].x-1:n),1);
	}
	cout<<ans<<endl;
	
	return 0; 
}