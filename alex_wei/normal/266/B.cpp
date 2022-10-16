#include <bits/stdc++.h>
using namespace std;
int n,t;
string s; 
int main()
{
	cin>>n>>t>>s;
	for(int i=0;i<t;i++)
		for(int j=0;j<s.size()-1;j++)
			if(s[j]=='B'&&s[j+1]=='G')
				swap(s[j],s[j+1]),j++;
	cout<<s;
    return 0;
}