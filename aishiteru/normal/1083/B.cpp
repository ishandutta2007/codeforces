#include<stdio.h>
#include<string.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
int n,k;
long long ans;
char s[N],t[N];
int main(){ 
	scanf("%d%d%s%s",&n,&k,s+1,t+1);it i,lst=1,now;
	for(i=1;i<=n;++i) now=(lst<<1)-(s[i]=='b')-(t[i]=='a'),lst=(now>k?k+1:now),ans+=(now<k?now:k);
	printf("%lld",ans);
	return 0;
}