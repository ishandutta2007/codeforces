#include <iostream>
using namespace std;
long long l,r,k,u,a[1000],k1,n,ans;
int main() 
{
	cin>>l>>r>>k;
	k1=k;
	n=1000000000000000000;
	while (n>=k)
	{
		n/=k;
		u++;
	}
	u++;
	k=1;
	for (int i=1;i<=u;i++)
	{
		a[i]=k;
		k=k*k1;
	}
	for (int i=1;i<=u;i++)
	if ((l<=a[i])&&(r>=a[i])) 
	{
		cout<<a[i]<<' ';
	    ans++;
	}
	if (ans==0) cout<<-1;
	
}