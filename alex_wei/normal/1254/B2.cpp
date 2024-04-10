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

const int N=1e6+5;

ll n,a[N],b[N],s,ans=1e18;

ll calc(ll v){
	ll tmp=0,p=0;
	for(int i=1;i<=n;i++)p+=a[i],tmp+=min(p%v,v-p%v);
	while(s%v==0)s/=v;
	return tmp;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)a[i]=read(),s+=a[i];
	for(ll i=2;i*i<=s;i++)if(s%i==0)ans=min(ans,calc(i));
	if(s>1)ans=min(ans,calc(s));
	cout<<(ans<1e18?ans:-1);
	
	return 0; 
}