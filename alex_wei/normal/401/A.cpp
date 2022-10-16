#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,x,s,p;
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>p,s+=p;
	if(s==0)cout<<0;
	else cout<<(abs(s)-1)/x+1;
	return 0;
}