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
int n,a[N],T;
il int Max(ct p,ct q){return p>q?p:q;}
int main(){ 
	scanf("%d",&T);it i,s;
	while(T--){
		scanf("%d",&n),s=0;
		for(i=1;i<=n;++i) scanf("%d",&a[i]),s+=(a[i]==i&&a[i-1]!=i-1);
		s+=(a[n]!=n);
		printf("%d\n",2<s?2:s);
	}
	return 0;
}