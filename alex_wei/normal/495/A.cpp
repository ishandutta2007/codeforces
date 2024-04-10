#include<bits/stdc++.h>
using namespace std;
int s[10]={2,7,2,3,3,4,2,5,1,2}; 
int main()
{
	char x,y;
	cin>>x>>y;
	cout<<s[x^48]*s[y^48];
	return 0;
}