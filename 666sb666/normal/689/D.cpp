#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=200001;
int n,a[maxn],b[maxn],fa[maxn][20],fb[maxn][20];
long long ans=0;
inline int qmax(int i,int j)
{
	int k=log2(j-i+1);
	return max(fa[i][k],fa[j-(1<<k)+1][k]);
}
inline int qmin(int i,int j)
{
	int k=log2(j-i+1);
	return min(fb[i][k],fb[j-(1<<k)+1][k]);
}
int main()
{
	scanf("%d",&n);
	int p=(int)log2(n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)fa[i][0]=a[i],fb[i][0]=b[i];
	for(int j=1;j<=p;j++)
		for(int i=1;i<=n;i++)if(i+(1<<j)-1<=n)
		fa[i][j]=max(fa[i][j-1],fa[i+(1<<(j-1))][j-1]),fb[i][j]=min(fb[i][j-1],fb[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n;i++)if(a[i]==b[i])
	{
		int l=0,r=min(i-1,n-i),mid;
		while(l<r)
		{
			mid=(l+r+1)>>1;
			int p=qmax(i-mid,i+mid),q=qmin(i-mid,i+mid);
			if(p==q)l=mid;
			else r=mid-1;
		}
		ans+=(long long)l+1;
	}
	else if(a[i]<b[i])
	{
		int l=0,r=min(i-1,n-i),mid;
		while(l<r)
		{
			mid=(l+r)>>1;
			int p=qmax(i-mid,i+mid),q=qmin(i-mid,i+mid);
			if(p<q)l=mid+1;
			else r=mid;
		}
		if(qmax(i-l,i+l)==qmin(i-l,i+l))
		{
			int L=l,R=min(i-1,n-i),MID;
			while(L<R)
			{
				MID=(L+R+1)>>1;
				int p=qmax(i-MID,i+MID),q=qmin(i-MID,i+MID);
				if(p==q)L=MID;
				else R=MID-1;
			}
			ans+=(long long)(L-l)+1;
		}
	}
	for(int i=1;i<n;i++)
	{
		int A=qmax(i,i+1),B=qmin(i,i+1);
		if(A==B)
		{
			int l=0,r=min(i-1,n-i-1),mid;
			while(l<r)
			{
				mid=(l+r+1)>>1;
				int p=qmax(i-mid,i+1+mid),q=qmin(i-mid,i+1+mid);
				if(p==q)l=mid;
				else r=mid-1;
			}
			ans+=(long long)l+1;
		}
		else if(A<B)
		{
			int l=0,r=min(i-1,n-i-1),mid;
			while(l<r)
			{
				mid=(l+r)>>1;
				int p=qmax(i-mid,i+1+mid),q=qmin(i-mid,i+1+mid);
				if(p<q)l=mid+1;
				else r=mid;
			}
			if(qmax(i-l,i+1+l)==qmin(i-l,i+1+l))
			{
				int L=l,R=min(i-1,n-i-1),MID;
				while(L<R)
				{
					MID=(L+R+1)>>1;
					int p=qmax(i-MID,i+1+MID),q=qmin(i-MID,i+1+MID);
					if(p==q)L=MID;
					else R=MID-1;
				}
				ans+=(long long)(L-l)+1;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}