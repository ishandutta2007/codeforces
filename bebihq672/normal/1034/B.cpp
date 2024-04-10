#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	if(n>=3&&m>=3)
	{
		cout<<(1ll*n*m/2)*2<<endl;
		return 0;
	}
	if(m<n)
		swap(n,m);
	if(n==1)
	{
		cout<<(m/6*3+max(m%6-3,0))*2<<endl;;
		return 0;
	}
	if(m==7)
	{
		cout<<12<<endl;
		return 0;
	}
	if(m<=2)
	{
		cout<<0<<endl;
		return 0;
	}
	if(m>=4)
	{
		cout<<2*m<<endl;
		return 0;
	}
	if(m==3)
	{
		cout<<4<<endl;
		return 0;
	}
	return 0;
}