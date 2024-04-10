#include<bits/stdc++.h>
using namespace std;
int n,a,b,c; 
int main()
{
	cin>>a>>b>>c>>n;
	if(c>a||c>b||a+b-c>=n||a>=n||b>=n)
		cout<<-1;
	else cout<<n-(a+b-c);
	return 0;
}