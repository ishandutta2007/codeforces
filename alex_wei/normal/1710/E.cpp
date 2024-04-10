// original classic problem, thanks
#include <bits/stdc++.h>
#define inf 1000000007
#define mod 1000000007
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
template <typename T> void write(T x) {
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n,m;
int a1,b1;
int a[200005];
int b[200005];
long long s[200005];
bool check(int mid)
{
	if(a[a1]+b[b1]<=mid) return 1;
	for(int i=1,j=m;i<=n;++i)
	{
		while(j&&a[i]+b[j]>mid) --j;
		s[i]=s[i-1]+j;
	}
	long long mx=0;bool res=0;
	for(int i=m,j=n,k=0;i>=1;--i)
	{
		while(j&&s[j]-s[j-1]+i<m) --j;
		long long t=s[j]-1ll*i*(n-k)-1ll*j*(m-i)+s[n]-s[k];
		if(mx<t) mx=t,res=0;
		if(mx==t) res|=(a1<=j||b1<=i);
		while(k<n&&s[k+1]-s[k]==i) ++k;
	}
	return res;
}
signed main()
{
	read(n);read(m);
	for(int i=1;i<=n;++i)
		read(a[i]);
	for(int i=1;i<=m;++i)
		read(b[i]);
	a1=a[1];b1=b[1];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;++i)
		if(a[i]==a1)
		{
			a1=i;break;
		}
	for(int i=1;i<=m;++i)
		if(b[i]==b1)
		{
			b1=i;break;
		}
	int l=1,r=inf;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	writeln(l);
	return 0;
}