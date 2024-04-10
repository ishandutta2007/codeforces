#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int dd=1ll*n*(n-1)/2%n,ll=0;
	long long tt=0;
	for(int i=1;i<=k;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--,ll=(ll+1ll*a*b)%n,tt+=b;
	}
	if(tt<n)cout<<1<<endl;
	else if(tt>n)cout<<-1<<endl;
	else if(tt==n)
	{
		if(ll==dd)cout<<1<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}