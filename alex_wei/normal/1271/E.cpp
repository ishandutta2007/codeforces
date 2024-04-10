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

ll n,k,ans;

ll bit(ll x){
	ll c=0;
	while(x)c++,x>>=1;
	return c;
}
ll calc(ll x){
	if(bit(n)==bit(x))return 1;
	ll s=(1ll<<bit(n)-bit(x))-1,r=n>>bit(n)-bit(x);
	return r>x?(s<<1)+1:r<x?s:s+n-(r<<bit(n)-bit(x))+1;
}

int main(){
	cin>>n>>k;
	if(n==k)puts("1"),exit(0);
	ll l=1,r=n>>1;
	while(l<r){
		ll m=(l+r>>1)+1,mm=m<<1;
		if(calc(mm)+calc(mm+1)>=k)l=m;
		else r=m-1;
	}
	ans=l<<1;
	l=1,r=(n+1)>>1;
	while(l<r){
		ll m=(l+r>>1)+1,mm=(m<<1)-1;
		if(calc(mm)>=k)l=m;
		else r=m-1;
	}
	cout<<max(ans,(l<<1)-1);
	
	return 0; 
}