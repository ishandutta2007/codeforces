//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.2 /////////////////
////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
#define ll long long
ll n,a[100],c[5],ans[5],money;
int main()
{ 
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<5;i++)
		cin>>c[i];
	for(int i=0;i<n;i++)
	{
		money+=a[i];
		for(int j=4;j>=0;j--)
			if(money>=c[j])
	        {
				ans[j]+=money/c[j];
				money%=c[j];
			}
	}	
	for(int i=0;i<5;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	cout<<money;	
    return 0;
}