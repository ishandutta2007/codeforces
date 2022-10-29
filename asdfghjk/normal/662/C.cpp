#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,i,j,k,p[100005];
char s[100005];
ll a[2000005],b[2000005],ans;
inline void Read(int &x)
{
	char c;
	while((c=getchar())<'0'||c>'9');
	x=c-'0';
	while((c=getchar())>='0'&&c<='9')
		x=x*10+c-'0';
}
inline void fwtxor(ll a[2000005],int t)
{
	for(int l=2;l<=(1<<n);l<<=1)
	{
		int m=l>>1;
		for(int i=0;i<(1<<n);i+=l)
			for(int j=0;j<m;++j)
			{
				ll x=a[i+j],y=a[i+j+m];
				a[i+j+m]=(t==1?x-y:(x-y)/2);
				a[i+j]=(t==1?x+y:(x+y)/2);
			}
	}
}
int main()
{
	Read(n);Read(m);
	for(i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(j=1;j<=m;++j)
			if(s[j]=='1')
				p[j]|=(1<<(i-1));
	}
	for(i=1;i<=m;++i)
		a[p[i]]++;
	for(i=0;i<(1<<n);++i)
	{
		for(j=k=0;j<n;++j)
			if((1<<j)&i)
				++k;
		b[i]=min(k,n-k);
	}
	fwtxor(a,1);
	fwtxor(b,1);
	for(i=0;i<(1<<n);++i)
		a[i]*=b[i];
	fwtxor(a,-1);
	ans=1ll<<60;
	for(i=0;i<(1<<n);++i)
		ans=min(ans,a[i]);
	printf("%lld",ans);
	return 0;
}