#include<bits/stdc++.h>
using namespace std;
int d[101],s,a,n; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a,d[i]=d[i-1]^a;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<=n;j++)
			s=max(s,d[i]^d[j]);
	cout<<s;
	return 0;
}