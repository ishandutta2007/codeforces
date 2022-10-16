#include<bits/stdc++.h>
using namespace std;
long long a,b,c; 
int main()
{
	cin>>a>>b>>c;
	cout<<4*(sqrt(a*b/c)+sqrt(b*c/a)+sqrt(a*c/b));
	return 0;
}