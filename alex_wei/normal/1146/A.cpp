#include<bits/stdc++.h>
using namespace std;
string s;
int c; 
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		c+=s[i]=='a';
	cout<<min((int)s.size(),c*2-1);
    return 0;
}