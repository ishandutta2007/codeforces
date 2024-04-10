#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sort(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

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
void print(int x){
	if(x>9)print(x/10);
	pc(x%10+'0');
}

const int N=4e3+5;
ll n,t[N],c[N],dp[N];
int main(){
	cin>>n;
	mem(dp,0x3f),dp[0]=0;
	for(int i=1;i<=n;i++)cin>>t[i]>>c[i],t[i]++;
	for(int i=1;i<N;i++)for(int j=N-1;j>=t[i];j--)dp[j]=min(dp[j],dp[j-t[i]]+c[i]);
	ll ans=1e18;
	for(int i=n;i<N;i++)ans=min(ans,dp[i]);
	cout<<ans<<endl;
    return 0;
}