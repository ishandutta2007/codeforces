#include<stdio.h>
#include<set>
#include<assert.h>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005;
#define P 1000000007
int f[N][3],cn[5],L,R,n;
il int Min(ct p,ct q){return p<q?p:q;}
il int A(ct x){return x<0?-x:x;}
il void mo(it &p,ct q){p+=q,p=(p>=P?p-P:p);}
struct ky{
	int n,m,a[5][5];
	ky operator * (const ky&p)const{
		register ky c;c.n=n,c.m=p.m;
		for(it i=0,j,k;i<c.n;++i)
			for(j=0;j<c.m;++j)
				for(c.a[i][j]=0,k=0;k<p.m;++k)
					c.a[i][j]=(c.a[i][j]+(0ll+a[i][k])*p.a[k][j])%P;
		return c;
	}
}o,ans;
int main(){ 
	scanf("%d%d%d",&n,&L,&R),cn[0]=cn[1]=cn[2]=(R-L+1)/3;
	L+=cn[0]*3;while(L<=R) ++cn[L%3],++L;
	o.n=o.m=3,o.a[0][0]=o.a[1][1]=o.a[2][2]=cn[0],o.a[0][1]=o.a[1][2]=o.a[2][0]=cn[1],o.a[0][2]=o.a[1][0]=o.a[2][1]=cn[2];
	ans.n=1,ans.m=3,ans.a[0][0]=1;
	while(n) n&1?ans=ans*o,0:0,o=o*o,n>>=1;
	printf("%d",ans.a[0][0]);
	return 0;
}