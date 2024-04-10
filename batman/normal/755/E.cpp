#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1001*1000)
#define K ((ll)20)


ll n,k;

int main()
{
	cin>>n>>k;
	if(k>3 || k==1 || (n==4 && k==2) || n<4)return cout<<-1,0;
	if(k==2)
	{
		cout<<n-1<<"\n";
		cout<<"1 2\n2 3\n3 4\n";
		for(int i=5;i<=n;i++)cout<<"4 "<<i<<"\n";
		return 0;
	}
	cout<<2*n-5<<"\n1 2\n2 3\n3 4\n";
	for(int i=5;i<=n;i++)cout<<"2 "<<i<<"\n3 "<<i<<"\n";
	return 0;
}