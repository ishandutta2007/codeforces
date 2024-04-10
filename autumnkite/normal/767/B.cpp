#include <cstdio>
#include <cctype>
const int N=100005;
int n;
long long ts,tf,t,sum,tmp,a[N],ans=1000000000000000000ll,id;
long long read(){
	long long x=0;
	int f=1,ch=getchar();
	for (;!isdigit(ch)&&ch!=EOF;ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^'0');
	return x*f;
}
long long min(long long a,long long b){return a<b?a:b;}
long long max(long long a,long long b){return a>b?a:b;}
int main(){
	ts=read(),tf=read(),t=read(),n=read();
	for (register int i=1;i<=n;++i) a[i]=read();
	sum=ts;
	for (register int i=1;i<=n;++i){
		if (max(sum,a[i]-1)>tf-t) break;
		tmp=sum-min(sum,a[i]-1);
		if (tmp<ans) ans=tmp,id=i;
		sum=max(sum,a[i])+t;
	}
	if (sum<=tf-t) printf("%I64d",sum);
	else printf("%I64d",a[id]-1);
}