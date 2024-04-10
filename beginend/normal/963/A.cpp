#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100005;
const int MOD=1000000009;

int n,a,b,k;
char str[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&k);
	int ny=ksm(a,MOD-2),w=ksm(a,n),fir=0;
	scanf("%s",str);
	for (int i=0;i<k;i++)
	{
		if (str[i]=='+') (fir+=w)%=MOD;
		else (fir+=MOD-w)%=MOD;
		w=(LL)w*b%MOD*ny%MOD;
	}
	int p=ksm((LL)b*ny%MOD,k);
	int ans=0;
	if (p!=1) ans=(LL)(ksm(p,(n+1)/k)-1)*ksm(p-1,MOD-2)%MOD*fir%MOD;
	else ans=(LL)fir*((n+1)/k)%MOD;
	printf("%d",ans);
	return 0;
}