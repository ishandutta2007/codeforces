#include<bits/stdc++.h>
using namespace std;
int t,a,b;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&a,&b);
		int ans=b-a;
		for (int A=a;A<b;++A)
		{
			int B=0;
			for (int i=21;i>=0;--i)
				if (b&(1<<i))
					B|=(1<<i);
				else
				{
					if (A&(1<<i))
					{
						B|=A;
						break;
					}
				}
			ans=min(ans,(A-a)+(B-b)+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}