#include <iostream>
using namespace std;

int n,m,x;
char minim[1002],maxim[1002];
bool funkc (int sum,int k)
{
	if(sum+k*9>=x && sum<=x)
		return true;
	return false;
}
int main()
{
	int i,j;
	cin>>n>>x;
	if(n==1 && x==0)
	{
		cout<<"0 0"<<endl;
		return 0;
	}
	if(!(n*9>=x && x>=1))
	{
		cout<<"-1 -1"<<endl;
		return 0;
	}
	int sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<10;j++)
		{
			if(i==0 && j==0)
				continue;
			if(funkc(sum+j,n-i-1)==true)
			{
				sum+=j;
				minim[i]=j+'0';
				j=10;
			}
		}
	}
/////////////////////////////////////////////////////
	sum=0;
	for(i=0;i<n;i++)
	{
		for(j=9;j>=0;j--)
		{
			if(i==0 && j==0)
				continue;
			if(funkc(sum+j,n-i)==true)
			{
				sum+=j;
				maxim[i]=j+'0';
				j=-1;
			}
		}
	}
	cout<<minim<<' '<<maxim<<endl;
	return 0;
}