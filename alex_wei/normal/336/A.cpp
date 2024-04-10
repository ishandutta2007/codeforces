#include<bits/stdc++.h>
using namespace std;
long long x,y; 
int main()
{
	cin>>x>>y;
	if(x*y>0)x>0?cout<<"0 "<<x+y<<" "<<x+y<<" 0":cout<<x+y<<" 0 0 "<<x+y;
	else x<0?cout<<x-y<<" 0 0 "<<y-x:cout<<"0 "<<y-x<<" "<<x-y<<" 0";
	return 0;
}