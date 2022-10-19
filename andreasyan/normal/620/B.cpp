#include <iostream>
using namespace std;

int a[10]={6,2,5,5,4,5,6,3,7,6};
long long ans;
int main()
{
	int i,x,y,k;
	cin>>x>>y;
	for(i=x;i<=y;++i)
	{
		k=i;
		if(k==0)
		{
			ans+=a[0];
		}
		while(k)
		{
			ans+=a[k%10];
			k/=10;
		}
	}
	cout<<ans<<endl;
	return 0;
}