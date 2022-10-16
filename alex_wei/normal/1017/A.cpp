#include<bits/stdc++.h>
using namespace std;
int s,a,b,c,d,t,n;
int main()
{
	cin>>n>>a>>b>>c>>d,s=a+b+c+d;
	for(int i=1;i<n;i++)
		cin>>a>>b>>c>>d,t+=a+b+c+d>s;
	cout<<t+1;
    return 0;
}