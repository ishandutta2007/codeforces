#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int main()
{
	cin>>n>>m;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			if(i*i+j==n&&i+j*j==m)
				s++;
	cout<<s;
	return 0;
}