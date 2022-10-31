#include<stdio.h>
#include<string.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
#define P 1000000007
const int N=1000005;
int n,a[N][2];
char s[N];
int main(){ 
	scanf("%d%s",&n,s+1);it i;
	for(i=1;i<=n;++i){
		a[i][0]=a[i-1][0],a[i][1]=a[i-1][1];
		if(s[i]!='?') a[i][s[i]&1^1]=i;
	}
	for(i=1;i<=n;++i){
		it pos=0,ans=0;
		while(pos+i<=n) (a[pos+i][0]==a[pos][0]||a[pos+i][1]==a[pos][1])?pos+=i,++ans:pos=a[pos+i][a[pos+i][1]<a[pos+i][0]];
		printf("%d ",ans);
	}
	return 0;
}