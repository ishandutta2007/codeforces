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

const int N=3e5+5;

ll a[N],b[N],ex[N],n;

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i],&b[i]);
	ll ans=1e18,tmp=0;
	for(int i=1;i<=n;i++){
		int prev=i-1;
		if(!prev)prev=n;
		ex[i]=a[i]-min(a[i],b[prev]);
		tmp+=ex[i];
	}
	for(int i=1;i<=n;i++)ans=min(ans,tmp+a[i]-ex[i]);
	cout<<ans<<endl;
}

int main(){
	int testcase=1;
	cin>>testcase;
	while(testcase--)solve();
	
	return 0;
}