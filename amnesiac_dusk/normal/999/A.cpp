#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	bool hola=false;
	for(int i=1; i<=n; i++)
		if(a[i]>k)
			hola=true;
	if(!hola)
	{
		cout<<n;
		return 0;
	}
	int i1=1,i2=n;
	for(;;i1++)
		if(a[i1]>k)
			break;
	for(;;i2--)
		if(a[i2]>k)
			break;
	cout<<i1+n-i2-1<<"\n";
	return 0;
}