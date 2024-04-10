#include<bits/stdc++.h>
using namespace std;
int n,f[1000],a;
int main()
{
	cin>>n,f[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=a;j<1000;j++)
			if(f[j-a])f[j]=1;
	}
	for(int i=1;i<1000;i++)
		if(!f[i])cout<<i,exit(0);
	cout<<-1;
	return 0;
}