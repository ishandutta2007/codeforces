#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		int n,f=0,p=-1;
		scanf("%d",&n);
		for(int i=1,x,y;i<=n;i++)
		{
			scanf("%d",&x);
			if(i>1&&abs(y-x)>=2)f=1,p=i;
			y=x;
		} 
		puts(f==1?"YES":"NO");
		if(f)printf("%d %d\n",p-1,p);
	}
	return 0;
}