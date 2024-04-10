#include<bits/stdc++.h>
using namespace std;
int n,p;
string s;
int main()
{
	cin>>n>>s;
	for(int i=1;i<n;i++)
		if(s[i]==s[i-1])p++;
	cout<<p;
	return 0;
}