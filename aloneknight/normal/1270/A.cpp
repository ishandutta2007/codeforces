#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		int n,n1,n2,f=0;
		scanf("%d%d%d",&n,&n1,&n2);
		for(int i=1,x;i<=n1;i++)
		{
			scanf("%d",&x);
			if(x==n)f=1;
		} 
		for(int i=1,x;i<=n2;i++)
		{
			scanf("%d",&x);
			if(x==n)f=2;
		} 
		puts(f==1?"YES":"NO");
	}
	return 0;
}