#include<bits/stdc++.h>
using namespace std;
int n,d[1000002];
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
		if(!d[i])
			for(int j=i+i;j<=n;j+=i)
				d[j]=1;
	for(int i=4;i<=n/2;i++)
		if(d[i]&&d[n-i])cout<<i<<" "<<n-i,exit(0);
    return 0;
}