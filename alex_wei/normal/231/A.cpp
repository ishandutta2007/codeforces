#include<bits/stdc++.h>
using namespace std;
int n,a[1002],c,k;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<4;j++)
			cin>>k,a[i]+=k;
	for(int i=1;i<=n;i++)
		if(a[i]>=2)c++;
	cout<<c;
	return 0;
}