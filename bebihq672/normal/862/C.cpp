#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,x;
	cin>>n>>x;
	if(n==1)
	{
		cout<<"YES"<<endl;
		cout<<x<<endl;
		return 0;
	}
	if(n==2)
	{
		if(x==0)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			cout<<1<<" "<<(x^1)<<endl;
		}
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n-3;i++)
	{
		cout<<i<<" ";
		x^=i;
	}
	if((x^(n-2))!=0)
	{
		cout<<n-2<<" ";
		x^=n-2;
	}
	else
	{
		cout<<n-1<<" ";
		x^=n-1;
	}
	cout<<(x^(1<<18))<<" "<<(1<<18)<<endl;
	return 0;
}