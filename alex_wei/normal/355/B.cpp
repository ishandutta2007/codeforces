#include<bits/stdc++.h>
using namespace std;
int c1,c2,c3,c4,n,m,a,b,s1,s2,s3;
int main()
{
	cin>>c1>>c2>>c3>>c4>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a,s1+=min(c2,c1*a);
	for(int i=1;i<=m;i++)
		cin>>b,s2+=min(c2,c1*b);
	s1=min(s1,c3),s2=min(s2,c3);
	cout<<min(s1+s2,c4);
	return 0;
}