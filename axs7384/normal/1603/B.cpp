#include<bits/stdc++.h>
using namespace std;
int t,x,y;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&x,&y);
		if (x==y)
		{
			cout<<x<<endl;
			continue;
		}
		if (x>y)
		{
			cout<<x+y<<endl;
			continue;
		}
		cout<<y-y%x/2<<endl;
	}
	return 0;
}