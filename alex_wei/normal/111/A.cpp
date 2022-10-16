#include<bits/stdc++.h>
using namespace std;
long long n,x,y; 
int main()
{
	cin>>n>>x>>y;
	if(n>y||(y-n+1)*(y-n+1)+n-1<x)cout<<-1;
	else for(int i=1;i<=n;i++)cout<<(i==1?y-n+1:1)<<endl;
	return 0; 
}