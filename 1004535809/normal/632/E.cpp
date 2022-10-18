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
const int pr=5;
const int MOD=924844033;
const int MAXP=1<<20;
int n,m,ipr;
int qpow(int x,int e){int ret=1;for(;e;x=1ll*x*x%MOD,e>>=1) if(e&1) ret=1ll*ret*x%MOD;return ret;}
int a[MAXP+5],LEN=(1<<20),LOG=20,rt[MAXP+5][2],rev[MAXP+5],inv[MAXP+5];
void NTT(int *a,int len,int type){
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		int W=rt[i][type<0];
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
int main(){
	scanf("%d%d",&n,&m);ipr=qpow(pr,MOD-2);
	for(int i=1;i<=n;i++){int x;scanf("%d",&x);a[x]++;}
	for(int i=0;i<LEN;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(LOG-1));
	for(int i=1;i<=LEN;i<<=1){
		inv[i]=qpow(i,MOD-2);
		rt[i][0]=qpow(pr,(MOD-1)/i);
		rt[i][1]=qpow(ipr,(MOD-1)/i);
	}
	NTT(a,LEN,1);
	for(int i=0;i<LEN;i++) a[i]=qpow(a[i],m);
	NTT(a,LEN,-1);
	for(int i=0;i<LEN;i++) if(a[i]) printf("%d ",i);
	return 0;
}