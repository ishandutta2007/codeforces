#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long tmp=1;
	while(tmp*10<=n)
		tmp*=10;
	tmp--;
	int ans=0;
	n-=tmp;
	while(n>0)
	{
		ans+=n%10;
		n/=10;
	}
	while(tmp>0)
	{
		ans+=tmp%10;
		tmp/=10;
	}
	cout<<ans<<endl;
	return 0;
}