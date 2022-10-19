#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k,a[100003],x;
long long ans;
int main()
{
	int i,j=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(x%2==0)
		{
			ans+=x;
		}
		else
		{
			a[j]=x;
			j++;
		}
	}
	sort(a,a+j);
	for(i=j-1;i>=0;)
	{
		if(i-1>=0)
		{
			ans+=a[i]+a[i-1];
			i=i-2;
		}
		else
			break;
	}
	cout<<ans<<endl;
	return 0;
}