#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
int main()
{
	cin>>a>>b>>c;
	for(int i=2;i<=c;i++)
		d=a+b,a=b,b=d;
	cout<<b;
	return 0;
}