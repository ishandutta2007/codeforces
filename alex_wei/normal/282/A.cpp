#include<bits/stdc++.h>
using namespace std;
#define ac ak
int n,x;
string s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s,s[1]=='+'?x++:x--;
	cout<<x;
	return 0;
}