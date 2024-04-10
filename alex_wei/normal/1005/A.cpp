#include<bits/stdc++.h>
using namespace std;
int n,m,c[1002],s; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i],s+=c[i]==1;
	cout<<s<<endl;
	c[n+1]=1;
	for(int i=2;i<=n+1;i++)
		if(c[i]==1)cout<<c[i-1]<<" "; 
    return 0;
}