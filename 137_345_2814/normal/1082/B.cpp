#include<cstdio>
#include<algorithm>
using namespace std;
char b;
int n,sum,s[100001],l,r;
int main()
{
	scanf("%d",&n);
	scanf("\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&b);
		if(b=='G')
		{
			sum++,r=i;
			if(l==0)l=i;
		}
		s[i]=sum;
	}
	int ans7=0;
	for(int i=1;i<=n;i++)
	if(s[i]==s[i-1])
	{
		int lb=1,rb=i-1,ans=0;
		while(lb<=rb)
		{
			int mid=(lb+rb)>>1;
			int tmp=s[i]-s[mid-1];
			if(mid<=l&&l<i)
			tmp--;
			if(tmp==i-mid)
			ans=i-mid,rb=mid-1;
			else
			lb=mid+1;
		}
		lb=i+1,rb=n;
		int ans2=0;
		while(lb<=rb)
		{
			int mid=(lb+rb)>>1;
			int tmp=s[mid]-s[i];
			if(tmp==mid-i)
			ans2=mid-i,lb=mid+1;
			else
			rb=mid-1;
		}
		int ans3=ans+ans2;
		if(l>i)ans3=0;
		lb=1,rb=i-1,ans=0;
		while(lb<=rb)
		{
			int mid=(lb+rb)>>1;
			int tmp=s[i]-s[mid-1];
			if(tmp==i-mid)
			ans=i-mid,rb=mid-1;
			else
			lb=mid+1;
		}
		lb=i+1,rb=n;
		 ans2=0;
		while(lb<=rb)
		{
			int mid=(lb+rb)>>1;
			int tmp=s[mid]-s[i];
			if(r<=mid&&r>i)tmp--;
			if(tmp==mid-i)
			ans2=mid-i,lb=mid+1;
			else
			rb=mid-1;
		}
		int ans4=ans+ans2;
		if(r<i)ans4=0;
		ans7=max(ans7,max(ans4,ans3));
	}
	if(ans7==0&&l!=r)
	ans7=n-1;
	if(l==0)ans7=-1;
	printf("%d\n",ans7+1);
}