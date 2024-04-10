#include<bits/stdc++.h>
using namespace std;
int n; 
int main()
{
	cin>>n;
	if(n>0)cout<<n;
	else cout<<max((n/100)*10+n%10,n/10);
	return 0;
}