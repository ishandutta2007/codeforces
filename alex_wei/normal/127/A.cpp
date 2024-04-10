#include<bits/stdc++.h>
using namespace std;
double n,a,b,c,d,s,k;
int main()
{
	cin>>n>>k>>a>>b;
	for(int i=1;i<n;i++)
		cin>>c>>d,s+=sqrt((a-c)*(a-c)+(b-d)*(b-d)),a=c,b=d;
	printf("%.6lf",s*k/50);
	return 0;
}