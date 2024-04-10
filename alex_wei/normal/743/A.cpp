#include<bits/stdc++.h>
using namespace std;
int n,a,b;
string s; 
int main()
{
	cin>>n>>a>>b>>s;
	cout<<(s[a-1]!=s[b-1]);
	return 0;
}