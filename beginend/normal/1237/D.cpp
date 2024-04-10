#include<bits/stdc++.h>

const int N=300005;

int n,a[N],stack[N],nx[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i+n]=a[i+n*2]=a[i];
	int top=0;
	for (int i=1;i<=n*3;i++)
	{
		while (top&&a[stack[top]]<=a[i]) top--;
		stack[++top]=i;
		int l=1,r=top;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (a[stack[mid]]>a[i]*2) l=mid+1;
			else r=mid-1;
		}
		nx[i]=stack[l-1];
	}
	int p=1;
	for (int i=1;i<=n;i++)
	{
		while (p<=n*3&&nx[p]<i) p++;
		if (p<=n*3) printf("%d ",p-i);
		else printf("%d ",-1);
	}
	return 0;
}