#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int LOG_N=31;
const int MAXK=1000;
const int LEN=1<<12;
const int pr=3;
const int MOD=7340033;
int qpow(int x,int e){int ret=1;for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;return ret;}
int A[LEN+5],inv[LEN+5],prs[LEN+5][2],rev[LEN+5],ipr;
int dp[LOG_N+2][MAXK+5];
void NTT(int *a,int len,int type){
	int lg=log2(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		int W=prs[i][type<0];
		for(int j=0;j<len;j+=i){
			int w=1;
			for(int k=0;k<(i>>1);k++,w=1ll*w*W%MOD){
				int X=a[j+k],Y=1ll*a[(i>>1)+j+k]*w%MOD;
				a[j+k]=(X+Y)%MOD;a[(i>>1)+j+k]=(X-Y+MOD)%MOD;
			}
		}
	}
	if(type==-1) for(int i=0;i<len;i++) a[i]=1ll*a[i]*inv[len]%MOD;
}
int main(){
	dp[0][0]=1;ipr=qpow(pr,MOD-2);
	for(int i=1;i<=LEN;i<<=1){
		inv[i]=qpow(i,MOD-2);
		prs[i][0]=qpow(pr,(MOD-1)/i);
		prs[i][1]=qpow(ipr,(MOD-1)/i);
	}
	for(int i=1;i<=LOG_N;i++){
		for(int j=0;j<LEN;j++) A[j]=0;
		for(int j=0;j<=MAXK;j++) A[j]=dp[i-1][j];
		NTT(A,LEN,1);
		for(int j=0;j<LEN;j++) A[j]=qpow(A[j],4);
		NTT(A,LEN,-1);
		for(int j=1;j<=MAXK;j++) dp[i][j]=A[j-1];
		dp[i][0]=1;
	}
	int qu;scanf("%d",&qu);
	while(qu--){
		int n,k;scanf("%d%d",&n,&k);
		int dep=0;while((n&1)&&n!=1) n>>=1,dep++;
		printf("%d\n",dp[dep][k]);
	}
	return 0;
}