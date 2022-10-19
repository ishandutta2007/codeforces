#include<bits/stdc++.h>
using namespace std;
int ans[400005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b;
		cin>>a>>b;
		int n=a+b,x=n+1>>1,y=n>>1;
		int m=0;
		for(int A=0;A<=a;A++)
		{
			int B=y-a+A;
			if(B<0||A>x||B>b||B>y)continue;
			ans[++m]=n-A-B;
		}
		swap(x,y);
		for(int A=0;A<=a;A++)
		{
			int B=y-a+A;
			if(B<0||A>x||B>b||B>y)continue;
			ans[++m]=n-A-B;
		}
		sort(ans+1,ans+m+1);
		m=unique(ans+1,ans+m+1)-ans-1;
		cout<<m<<endl;
		for(int i=1;i<=m;i++)printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}