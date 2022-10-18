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
const int MAXW=3e5;
const int MAXR=5;
const int MAXL=3e5;
const int MAXP=1<<19;
const int pr=3;
const int MOD=998244353;
int qpow(int x,int e){int ret=1;for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;return ret;}
int n,k,qu,a[MAXW+5],b[MAXR+5],c[MAXL+5];
int LEN=1,LOG=0,A[MAXP+5],B[MAXP+5],C[MAXP+5],ipr,rev[MAXP+5],inv[MAXP+5],prs[MAXP+5][2];
int f[MAXR+5][MAXW+5];
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
void solve(int x){
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++) if(a[i]<b[x]) c[a[i]]++;
	int c1=0,c2=0;
	for(int i=1;i<b[x];i++){
		if(c[i]==1) c1++;
		if(c[i]>=2) c2++;
	}
//	printf("%d %d\n",c1,c2);
	for(int i=0;i<LEN;i++) A[i]=B[i]=C[i]=0;
	A[0]=B[0]=B[2]=1;A[1]=B[1]=2;
	NTT(A,LEN,1);NTT(B,LEN,1);
	for(int i=0;i<LEN;i++) A[i]=qpow(A[i],c1);
	for(int i=0;i<LEN;i++) B[i]=qpow(B[i],c2);
	for(int i=0;i<LEN;i++) C[i]=1ll*A[i]*B[i]%MOD;
	NTT(C,LEN,-1);
//	for(int i=0;i<=n;i++) printf("%d ",C[i]);printf("\n");
	for(int i=0;i<=n;i++) f[x][i]=C[i];
}
int main(){
	scanf("%d%d",&n,&k);ipr=qpow(pr,MOD-2);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=k;i++) scanf("%d",&b[i]);
	while(LEN<=n) LEN<<=1,LOG++;
	for(int i=1;i<=LEN;i<<=1){
		inv[i]=qpow(i,MOD-2);
		prs[i][0]=qpow(pr,(MOD-1)/i);
		prs[i][1]=qpow(ipr,(MOD-1)/i);
	}
	for(int i=1;i<=k;i++) solve(i);
	scanf("%d",&qu);
	while(qu--){
		int x;scanf("%d",&x);x>>=1;x--;int ans=0;
		for(int i=1;i<=k;i++) if(x-b[i]>=0&&x-b[i]<=n) ans=(ans+f[i][x-b[i]])%MOD;
		printf("%d\n",ans);
	}
	return 0;
}