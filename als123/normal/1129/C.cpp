#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int MOD=1e9+7;
const int N=3005;
int n;
int f[N];//[i,j] 
int a[N];
bool get (int l,int r)// 
{
	if (r-l+1==4)
	{
		//0011   0101   1110   1111
		if (a[l]==0&&a[l+1]==0&&a[l+2]==1&&a[l+3]==1) return false;
		if (a[l]==0&&a[l+1]==1&&a[l+2]==0&&a[l+3]==1) return false;
		if (a[l]==1&&a[l+1]==1&&a[l+2]==1&&a[l+3]==0) return false;
		if (a[l]==1&&a[l+1]==1&&a[l+2]==1&&a[l+3]==1) return false;
	}
	return true;
}
struct qt
{
	int son[2];
}tr[N*N];int num;
int main()
{
	scanf("%d",&n);
	num=0;
	int ans=0;
	for (int u=1;u<=n;u++)
	{
		scanf("%d",&a[u]);
		int now=0;
		bool tf=false;f[u+1]=1;
		for (int i=u;i>=1;i--)
		{
			f[i]=0;
			int x=a[i];
			if (tr[now].son[x]==0)	{tf=true;tr[now].son[x]=++num;}
			now=tr[now].son[x];
			for (int k=i;k<=u;k++)
			{
				if (k-i+1>4) break;
				if (get(i,k)==true)	f[i]=(f[i]+f[k+1])%MOD;
			}
			if (tf) ans=(ans+f[i])%MOD;
		}
		printf("%d\n",ans);
	}
	return 0;
}