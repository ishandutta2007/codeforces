#include<bits/stdc++.h>
using namespace std;
int n; 
int main()
{
	cin>>n;
	if(n%2)cout<<-1,exit(0);
	else
		for(int i=0;i<n/2;i++)
			cout<<i*2+2<<" "<<i*2+1<<" ";
	return 0;
}