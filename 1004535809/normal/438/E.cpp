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
const int pr=3;
const int MAXP=1<<18;
const int INV2=499122177;
const int MOD=998244353;
int qpow(int x,int e){int ret=1;for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;return ret;}
int n,m,a[MAXP+5],b[MAXP+5],c[MAXP+5];
int A[MAXP+5],B[MAXP+5],C[MAXP+5],D[MAXP+5],E[MAXP+5],F[MAXP+5];
int LEN=1,LOG=0,inv[MAXP+5],prs[MAXP+5][2],rev[MAXP+5],ipr;
void NTT(int *a,int len,int type){
	int lg=log2(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		int W=prs[i][type<0];
		for(int j=0;j<len;j+=i){
			int w=1;
			for(int k=0;k<(i>>1);k++,w=1ll*w*W%MOD){
				int X=a[j+k],Y=1ll*w*a[(i>>1)+j+k]%MOD;
				a[j+k]=(X+Y)%MOD;a[(i>>1)+j+k]=(X-Y+MOD)%MOD;
			}
		}
	}
	if(type==-1) for(int i=0;i<len;i++) a[i]=1ll*a[i]*inv[len]%MOD;
}
void polymul(int *a,int *b,int *c,int len){
	for(int i=0;i<len;i++) A[i]=a[i],B[i]=b[i];
	NTT(A,len,1);NTT(B,len,1);
	for(int i=0;i<len;i++) c[i]=1ll*A[i]*B[i]%MOD;
	NTT(c,len,-1);
}
void getinv(int *a,int *b,int len){
	for(int i=0;i<len;i++) b[i]=0;
	b[0]=qpow(a[0],MOD-2);
	for(int i=2;i<=len;i<<=1){
		for(int j=0;j<(i<<1);j++) C[j]=D[j]=0;
		for(int j=0;j<i;j++) C[j]=a[j];
		for(int j=0;j<(i>>1);j++) D[j]=b[j];
		polymul(D,D,D,i);polymul(C,D,C,i<<1);
		for(int j=0;j<i;j++) b[j]=(2*b[j]%MOD-C[j]+MOD)%MOD;
	}
}
void getsqrt(int *a,int *b,int len){
	for(int i=0;i<len;i++) b[i]=0;
	b[0]=1;
	for(int i=2;i<=len;i<<=1){
		for(int j=0;j<(i<<1);j++) E[j]=F[j]=0;
		for(int j=0;j<(i>>1);j++) E[j]=b[j];
		polymul(E,E,E,i);
		for(int j=0;j<i;j++) E[j]=(E[j]+a[j])%MOD;
		getinv(b,F,i);polymul(E,F,E,i<<1);
		for(int j=0;j<i;j++) b[j]=1ll*E[j]*INV2%MOD;
	}
}
int main(){
	scanf("%d%d",&n,&m);ipr=qpow(pr,MOD-2);
	for(int i=1;i<=n;i++){int x;scanf("%d",&x);a[x]=1;}
	for(int i=1;i<=m;i++) a[i]=(MOD-4*a[i])%MOD;a[0]=1;
	while(LEN<=m) LEN<<=1,LOG++;
	for(int i=1;i<=(LEN<<1);i<<=1){
		inv[i]=qpow(i,MOD-2);
		prs[i][0]=qpow(pr,(MOD-1)/i);
		prs[i][1]=qpow(ipr,(MOD-1)/i);
	} getsqrt(a,b,LEN);
//	for(int i=0;i<LEN;i++) printf("%d%c",b[i],(i==LEN-1)?'\n':' ');
	b[0]++;getinv(b,c,LEN);
	for(int i=1;i<=m;i++) printf("%d\n",2*c[i]%MOD);
	return 0;
}