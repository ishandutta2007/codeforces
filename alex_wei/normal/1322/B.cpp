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

const int N=4e5+5;

int n,a[N],b[N],ans;

bool calc(int x,int y){
	if(x>y)return 0;
	ll res=0; int l=n+1,r=n;
	for(int i=1;i<=n;i++){
		while(l>1&&b[i]+b[l-1]>=x)l--;
		while(r&&b[i]+b[r]>y)r--;
		res+=r-l+1-(l<=i&&i<=r);
	}
	return (res>>1)&1;
}

bool solve(int x){
	for(int i=1;i<=n;i++)b[i]=a[i]&((1<<x+1)-1);
	sort(b+1,b+n+1);
	return calc(1<<x,(2<<x)-1)^calc(3<<x,(4<<x)-2);
}

int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=0;i<25;i++)ans+=solve(i)<<i; 
	cout<<ans<<endl;
	
	return 0;
}