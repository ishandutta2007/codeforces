#include<bits/stdc++.h>
using namespace std;
int a,b,c,s;
int main()
{
	cin>>a>>b>>c;
	s=(a*c-1)/b+1;
	cout<<s-c;
	return 0;
}