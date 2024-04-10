#include<bits/stdc++.h>
using namespace std;
int a,b,k,t; 
int main()
{
	cin>>a>>b>>k;
	t=(b+k+a*100)%a;
	cout<<(t==0?a:t);
	return 0;
}