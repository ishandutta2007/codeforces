#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int t=1;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		int g1=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),g1+=a[i];
		for(int i=1;i<=q;i++)
		{
			int op,x;
			scanf("%d%d",&op,&x);
			if(op==1)
			{
				if(a[x]==1)g1--;
				else g1++;
				a[x]=!a[x];
			}else
			{
				if(x<=g1)printf("1\n");
				else printf("0\n");
			}
		}
	}
	return 0;
}