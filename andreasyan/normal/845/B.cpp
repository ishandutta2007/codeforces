#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans;
int a[7];
int main()
{
	char b[10];
	cin>>b;
	int ans=0;
	int sum1=0;
	int sum2=0;
	for(int i=0;i<3;++i)
	{
		a[i]=b[i]-'0';
		sum1+=(a[i]);
	}
	for(int i=3;i<6;++i)
	{
		a[i]=b[i]-'0';
		sum2+=(a[i]);
	}
	///////////////////////////
	if(sum1>sum2)
	{
		int c[10];
		for(int i=0;i<3;++i)
			c[i]=a[i];
		for(int i=0;i<3;++i)
			a[i]=a[i+3];
		for(int i=0;i<3;++i)
			a[i+3]=c[i];
		int sum3=sum1;
		sum1=sum2;
		sum2=sum3;
	}
	sort(a,a+3);
	sort(a+3,a+6);
	int x=sum2-sum1;
	int i1=0;
	int i2=5;
	while(x>0)
	{
		if(i1==3)
		{
			x-=(a[i2]);
			--i2;
			++ans;
			continue;
		}
		if(i2==2)
		{
			x-=(9-a[i1]);
			++i1;
			++ans;
			continue;
		}
		if((9-a[i1])>a[i2])
		{
			x-=(9-a[i1]);
			++i1;
			++ans;
		}
		else
		{
			x-=(a[i2]);
			--i2;
			++ans;
		}
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}