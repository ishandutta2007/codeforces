#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
#define int long long
typedef long long ll;
typedef unsigned long long ull;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T>
void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=2e5;
int n,m=3,k=2,a[MAXN+5],cnt[MAXN+5];
signed main(){
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n+1;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
		for(int i=n;i;i--) cnt[i]+=cnt[i+1];
		ll ans=0;
		for(int i=n;i;i--){
			int sum1=cnt[i]-((i+k+1<=n)?cnt[i+k+1]:0);
			int sum2=cnt[i+1]-((i+k+1<=n)?cnt[i+k+1]:0);
			int ret=1ll*sum1*(sum1-1)*(sum1-2)/6-1ll*sum2*(sum2-1)*(sum2-2)/6;
			ans+=ret;
		} cout<<ans<<endl;
	}
	return 0;
}