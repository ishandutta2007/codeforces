#include<bits/stdc++.h>
using namespace std;
int n,h[50],a[50],num; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i]>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(h[i]==a[j])
				num++;
	cout<<num;
	return 0;
}