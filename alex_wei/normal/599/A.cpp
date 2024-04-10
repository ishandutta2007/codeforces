#include<bits/stdc++.h>
using namespace std;
int a,b,c; 
int main()
{
	cin>>a>>c>>b;
	cout<<min(a+b+c,min(a+b+a+b,min(a+c+a+c,b+c+b+c)));
	return 0;
}