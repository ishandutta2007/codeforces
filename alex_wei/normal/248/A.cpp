#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,x,y,a1,a2; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x>>y,a1+=x==0,a2+=y==0;
	cout<<min(a1,n-a1)+min(a2,n-a2);
	return 0;
}