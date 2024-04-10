#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	for(int x=sqrt(n);x>0;x--)
		if(n%x==0)cout<<x<<" "<<n/x,exit(0);
    return 0;
}