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
const int MAXN=100;
int n,a[MAXN+5],b[MAXN+5],dp[MAXN+5][MAXN+5][MAXN*MAXN+5];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);memset(dp,128,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=0;i<n;i++) for(int j=0;j<=i;j++) for(int k=0;k<=10000;k++){
		if(k+a[i]<=10000) chkmax(dp[i+1][j+1][k+a[i+1]],dp[i][j][k]+b[i+1]*2);
		chkmax(dp[i+1][j][k],dp[i][j][k]+b[i+1]);
	}
	for(int i=1;i<=n;i++){
		double ans=0;
		for(int k=0;k<=10000;k++){
			ans=max(ans,min(1.0*k,dp[n][i][k]/2.0));
		}
		printf("%.10lf ",ans);
	}
	return 0;
}