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
const int MOD=1e9+7;
int n,m,k,a[MAXN+5],cnt[MAXN+5];
int f[MAXN+5],ff[MAXN+5];
int qpow(int x,int e){
	int ans=1;
	while(e){
		if(e&1) ans=1ll*ans*x%MOD;
		x=1ll*x*x%MOD;e>>=1;
	} return ans;
}
int func(int x,int y){
	if(x<y) return 0;
	return 1ll*f[x]*ff[y]%MOD*ff[x-y]%MOD;
}
int main(){
	int T;scanf("%d",&T);f[0]=1;
	for(int i=1;i<=MAXN;i++) f[i]=1ll*f[i-1]*i%MOD;
	for(int i=0;i<=MAXN;i++) ff[i]=qpow(f[i],MOD-2);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n+1;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
		for(int i=n;i;i--) cnt[i]+=cnt[i+1];
		int ans=0;
		for(int i=n;i;i--){
			int sum1=cnt[i]-((i+k+1<=n)?cnt[i+k+1]:0);
			int sum2=cnt[i+1]-((i+k+1<=n)?cnt[i+k+1]:0);
			int ret=(func(sum1,m)-func(sum2,m)+MOD)%MOD;
			ans=(ans+ret)%MOD;
		} printf("%d\n",ans);
	}
	return 0;
}