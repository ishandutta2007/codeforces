#include<bits/stdc++.h>
using namespace std;
int a,b,n;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)s[i]=='0'?a++:b++;
	cout<<abs(a-b);
	return 0;
}