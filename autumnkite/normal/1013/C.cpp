#include <cstdio>
#include <algorithm>
#include <cctype>
int read(){
	int x=0,f=1,ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=0;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^'0');
	return f?x:-x;
}
int n,a[200005];
long long ans;
int main(){
	n=read();
	for (register int i=1;i<=2*n;++i) a[i]=read();
	std::sort(a+1,a+1+2*n);
	ans=1ll*(a[n]-a[1])*(a[2*n]-a[n+1]);
	for (register int i=2;i<=n;++i) ans=std::min(ans,1ll*(a[2*n]-a[1])*(a[i+n-1]-a[i]));
	printf("%I64d",ans);
}