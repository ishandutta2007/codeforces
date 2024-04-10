#include <cstdio>
#include <cstring>
const int N=300005;
int n,x,y,cnt;
char s[N];
long long ans=1000000000000000000ll;
inline long long min(long long a,long long b){return a<b?a:b;}
int main(){
	scanf("%d%d%d",&n,&x,&y),scanf("%s",s+1),s[0]='1';
	for (register int i=1;i<=n;++i)
		if (s[i]=='0'&&s[i-1]=='1') ++cnt;
	if (cnt==0) return printf("0"),0;
	for (register int i=0;i<cnt;++i) ans=min(ans,1ll*i*x+1ll*(cnt-i)*y);
	printf("%I64d",ans);
}