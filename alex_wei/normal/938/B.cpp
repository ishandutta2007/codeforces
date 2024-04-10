#include <bits/stdc++.h>
using namespace std;
int n,a,p[1000002],k;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a,p[a]=1;
	for(int i=1;i<1e6;i++){
		k+=p[1+i]+p[(int)1e6-i];
		if(k==n)cout<<i,exit(0);
	}
    return 0;
}