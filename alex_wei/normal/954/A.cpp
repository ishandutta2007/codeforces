#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	cin>>n>>s;
	for(int i=1;i<s.size();i++)
		if(s[i]!=s[i-1])
			i++,n--;
	cout<<n;
	return 0;
}