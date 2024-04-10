#include<stdio.h>
#include<string.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005;
#define P 1000000007
char S[N];
int n,a[N],o,f[N];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%s",S+1),n=strlen(S+1);it i,j,x=0,s;
	for(i=1;i<=n;++i) S[i]=='1'?a[++*a]=x,x=0:++x;
	if(!a[0]) return printf("%d",n),0;
	for(i=2,o=1,s=0;i<=a[0];o=s^(P-1)?s+1:0,++i)
		for(j=0;j<=a[i];++j) s=s-f[j]+o,s=(s>=P?s-P:(s<0?s+P:s)),f[j]=o;
	printf("%d",(1ll+a[1])*(x+1ll)%P*o%P);
	return 0;
}