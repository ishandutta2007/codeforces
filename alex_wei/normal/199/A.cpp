#include<bits/stdc++.h>
using namespace std;
int n,f[60]; 
int main()
{
	cin>>n;
	f[1]=1;
	for(int i=2;f[i-1]<=n;i++)
		f[i]=f[i-1]+f[i-2];
	for(int i=0;i<3;i++)
		for(int j=59;j>=0;j--)
			if(f[j]&&f[j]<n||f[j]==n){cout<<f[j]<<" ",n-=f[j];break;}
	return 0;
}