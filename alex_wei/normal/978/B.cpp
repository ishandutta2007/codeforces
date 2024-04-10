#include<bits/stdc++.h>
using namespace std;
int n,ct,m;
#define aba ababa
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)s[i]=='x'?ct++:ct=0,m+=ct>2;
	cout<<m;
	return 0;
}