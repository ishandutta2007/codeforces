#include <bits/stdc++.h>
using namespace std;
int n,a[200002],s,cnt;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i],s+=a[i];
	if(s%n)cout<<0,exit(0);
	s/=n;
	for(int i=0;i<n;i++)
		if(a[i]==s)
			cnt++;
	cout<<cnt<<endl;
	for(int i=0;i<n;i++)
		if(a[i]==s)
			cout<<i+1<<" ";
    return 0;
}