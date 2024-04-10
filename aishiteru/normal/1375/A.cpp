#include<stdio.h>
#include<vector>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005;
int n,T,a[N];
int main(){ 
	scanf("%d",&T);it i;
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i) scanf("%d",&a[i]),a[i]=(a[i]<0?-a[i]:a[i]);
		for(i=1;i<=n;++i) printf("%d ",i&1?a[i]:-a[i]);puts("");
	}
	return 0;
}