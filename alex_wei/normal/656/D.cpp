#include<bits/stdc++.h>
using namespace std;
int a,s; 
int main()
{
	cin>>a;
	while(a)s+=a%8==1,a/=8;
	cout<<s;
	return 0;
}