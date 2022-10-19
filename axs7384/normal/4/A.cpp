#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
	cin>>n;
	if (n&1||n==2)
		cout<<"NO";
	else 
		cout<<"YES";
	return 0;
}