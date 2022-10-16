#include<bits/stdc++.h>
using namespace std;
string s,t;
int a,b;
int main()
{
	cin>>s>>t,a=s.size(),b=t.size();
	while(a&&b)
		if(s[a-1]!=t[b-1])
			break;
		else a--,b--;
	cout<<a+b;
	return 0;
}