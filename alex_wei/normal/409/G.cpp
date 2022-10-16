#include <bits/stdc++.h>
using namespace std;
double x,y,s,n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>y>>y,s+=y;
	printf("%.3lf",5+s/n);
    return 0;
}