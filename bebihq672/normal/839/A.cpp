#include<iostream>
using namespace std;
int a[10101];
int main()
{
	int n,k;
	cin>>n>>k;
	int sum=0,candy=0,ans=-1;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		sum+=x;
		if(sum>=8)
		{
			sum-=8;
			candy+=8;
		}
		else
		{
			candy+=sum;
			sum=0;
		}
		if(candy>=k)
		{
			ans=i;
			break; 
		} 	
	}
	cout<<ans<<endl;
	return 0;
}