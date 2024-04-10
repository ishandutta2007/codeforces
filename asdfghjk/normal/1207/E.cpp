#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int i,j,ans;
int main()
{
	cout<<'?';
	for(i=1;i<=100;++i)
		cout<<' '<<i;
	cout<<endl;
	fflush(stdout);
	cin>>i;
	for(j=0;j<7;++j)
		if(i>>j&1)
			i-=1<<j;
	ans=i;
	cout<<'?';
	for(i=0,j=1;j<=100;++j,i+=(1<<7))
		cout<<' '<<i;
	cout<<endl;
	fflush(stdout);
	cin>>i;
	ans+=i&((1<<7)-1);
	cout<<'!'<<' '<<ans<<endl;
	return 0;
}