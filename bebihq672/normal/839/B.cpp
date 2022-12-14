#include<iostream>
using namespace std;
int a[101010];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	int _2=2*n,_4=n;
	for(int i=1;i<=k;i++)
	while(a[i]>=4&&_4>0)
	{
		_4--;
		a[i]-=4;
	}
	for(int i=1;i<=k;i++)
	while(_2>0&&a[i]>=2)
	{
		a[i]-=2;
		_2--;
	}
	for(int i=1;i<=k;i++)
	while(_2>0&&a[i]>0)
	{
		a[i]--;
		_2--;
	}
	for(int i=1;i<=k;i++)
	for(int j=1;j<=k;j++)
	if(a[i]==2&&a[j]==1&&_4>0)
	{
		_4--;
		a[i]=0;
		a[j]=0;
	}
	for(int i=1;i<=k;i++)
	for(int j=1;j<=k;j++)
	for(int l=1;l<=k;l++)
	if(i!=j&&j!=l&&i!=l&&a[i]==2&&a[j]==2&&a[l]==2&&_4>1)
	{
		_4-=2;
		a[i]=0;
		a[j]=0;
		a[l]=0;
	}
	for(int i=1;i<=k;i++)
	for(int j=1;j<=k;j++)
	if(i!=j&&a[i]==1&&a[j]==1&&_4>0)
	{
		_4--;
		a[i]=0;
		a[j]=0;
	}
	for(int i=1;i<=k;i++)
	if(a[i]>0&&_4>0)
	{
		_4--;
		a[i]=0;
	}
	bool flag=0;
	for(int i=1;i<=k;i++)
	if(a[i]>0)
	{
		flag=1;
		break;
	}
	if(flag)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	return 0;
}