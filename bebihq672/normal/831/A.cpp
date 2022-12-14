#include<iostream>
using namespace std;
int a[101010];
int main()
{
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=n,r=1;
	for(int i=2;i<=n;i++)
	if(a[i]<=a[i-1])
	{
		l=i-1;
		break;
	}
	for(int i=n-1;i>=1;i--)
	if(a[i]<=a[i+1])
	{
		r=i+1;
		break;
	}
	if(r<=l)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	bool flag=0;
	for(int i=l+1;i<=r;i++)
	if(a[i]!=a[i-1])
	{
		flag=1;
		break;
	}
	if(flag==0)
	{
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;
	return 0;
}