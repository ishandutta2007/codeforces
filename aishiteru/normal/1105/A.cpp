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
int a[N],n;
il int Min(ct p,ct q){return p<q?p:q;}
il int A(ct x){return x<0?-x:x;}
int main(){ 
	scanf("%d",&n);it i,j,o=1e9,ans=0,id=0;
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	for(i=1;i<=101;ans<o?o=ans,id=i:0,++i)
		for(j=1,ans=0;j<=n;++j) ans+=Min(A(i-a[j]),Min(A(i-1-a[j]),A(i+1-a[j])));
	printf("%d %d",id,o);
	return 0;
}