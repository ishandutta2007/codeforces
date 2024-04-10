#include <bits/stdc++.h>
using namespace std;
double a,n,s,k; 
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a,s+=a;
	for(int i=0;i<10000000;i++){
		double c=s/(n+i);
		if(k-0.5<=c&&c<k+0.5)
			cout<<i,exit(0);
		s+=k;
	}
    return 0;
}