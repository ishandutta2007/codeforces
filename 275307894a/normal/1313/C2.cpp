#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
long long n,m,a[500039],s1[500039],s2[500039],l[500039],r[500039],f[500039],head,ans,tot,pus,now,z[500039];
inline void read(long long &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
inline void print(long long x){
	if(x>9) print(x/10);
	putchar(x%10+48);
}
int main(){
	register long long i,j;
	scanf("%lld",&n);
	for(i=1;i<=n;i++) read(a[i]);
	for(i=1;i<=n;i++) r[i]=n+1;
	for(i=1;i<=n;i++){
		while(head&&a[f[head]]>a[i]) r[f[head]]=i,head--;
		l[i]=f[head];
		f[++head]=i;
	}
	for(i=1;i<=n;i++) s1[i]=s1[l[i]]+a[i]*(i-l[i]);
	for(i=n;i>=1;i--) s2[i]=s2[r[i]]+a[i]*(r[i]-i);
	for(i=1;i<=n;i++) ans=max(ans,s1[i]+s2[i]-a[i]);
	for(i=1;i<=n;i++){
		if(ans==s1[i]+s2[i]-a[i]){
			z[i]=a[i];
			for(j=i-1;j>=1;j--)z[j]=min(z[j+1],a[j]);
			for(j=i+1;j<=n;j++)z[j]=min(z[j-1],a[j]);
			for(j=1;j<=n;j++) print(z[j]),putchar(' ');
			return 0;
		}
	}
}