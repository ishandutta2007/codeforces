#include<bits/stdc++.h>
using namespace std;
int n,a,s,p;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a,s+=a;
	for(int i=1;i<6;i++)
		if((s+i)%(n+1)!=1)
			p++;
	cout<<p<<endl;
	return 0;
}