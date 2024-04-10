#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if((x+y)%2==0&&x>=y)puts("0");
		else
		{
			int ans=0;
			if(x<y)ans+=y-x,x=y;
			else ans=1;
			printf("%d\n",ans);
		}
	}
	return 0;
}