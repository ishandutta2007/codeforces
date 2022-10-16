#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,ans; 
int main()
{
	cin>>n>>m>>a>>b;
	if(m*a<=b)cout<<a*n;
	else cout<<(n/m)*b+min(b,a*(n%m));
	return 0;
}