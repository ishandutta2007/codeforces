#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=1048580;

int n,m,a[100005],cnt[N],bin[25];
char str[100005];
LL s[N],val[N];

void fwt(LL *a,int l,int r)
{
	if (l==r) return;
	int len=(r-l+1)/2,mid=(l+r)/2;
	fwt(a,l,mid);fwt(a,mid+1,r);
	for (int i=0;i<len;i++)
	{
		LL x=a[l+i],y=a[mid+1+i];
		a[l+i]=x+y;a[mid+1+i]=x-y;
	}
}

void dwt(LL *a,int l,int r)
{
	if (l==r) return;
	int len=(r-l+1)/2,mid=(l+r)/2;
	dwt(a,l,mid);dwt(a,mid+1,r);
	for (int i=0;i<len;i++)
	{
		LL x=a[l+i],y=a[mid+1+i];
		a[l+i]=(x+y)/2;a[mid+1+i]=(x-y)/2;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	bin[0]=1;
	for (int i=1;i<=n;i++) bin[i]=bin[i-1]*2;
	for (int i=0;i<bin[n];i++) cnt[i]=cnt[i>>1]+(i&1),val[i]=min(cnt[i],n-cnt[i]);
	for (int i=0;i<n;i++)
	{
		scanf("%s",str+1);
		for (int j=1;j<=m;j++) a[j]+=(str[j]=='1')?bin[i]:0;
	}
	for (int i=1;i<=m;i++) s[a[i]]++;
	fwt(val,0,bin[n]-1);fwt(s,0,bin[n]-1);
	for (int i=0;i<bin[n];i++) s[i]*=val[i];
	dwt(s,0,bin[n]-1);
	int ans=n*m;
	for (int i=0;i<bin[n];i++) ans=min(ans,(int)s[i]);
	printf("%d",ans);
	return 0;
}