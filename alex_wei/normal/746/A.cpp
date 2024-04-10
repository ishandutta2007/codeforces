#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,c; 
int main()
{
	cin>>a>>b>>c;
	cout<<min(a,min(b/2,c/4))*7;
	return 0;
}