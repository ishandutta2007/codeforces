
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s,s1;
	cin>>s;
	s1=s;
	reverse(s1.begin(),s1.end());
	s+=s1;
	cout<<s;
	return 0;
}