#include<bits/stdc++.h>
using namespace std;
double a,b,n,c,d,v,s=1e9;
int main()
{
	cin>>a>>b>>n;
	for(int i=0;i<n;i++)
		cin>>c>>d>>v,s=min(s,sqrt((c-a)*(c-a)+(d-b)*(d-b))/v);
	printf("%.20lf",s);
	return 0;
}