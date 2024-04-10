#include <bits/stdc++.h>
using namespace std;
double n,p,s;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>p,s+=p;
	printf("%.5lf",s/n);
    return 0;
}