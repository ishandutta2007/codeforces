#include<bits/stdc++.h>
using namespace std;
long long l,r;
int main()
{
	cin>>l>>r;
	if(r-l<2||r-l==2&&l%2)cout<<-1,exit(0);
	cout<<l+l%2<<" "<<l+l%2+1<<" "<<l+l%2+2;
	return 0;
}