#include<bits/stdc++.h>
using namespace std;
int n,k,g[26],p=1e5;
string s;
int main()
{
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)
		g[s[i]-'A']++;
	for(int i=0;i<k;i++)
		p=min(g[i],p);
	cout<<p*k;
	return 0;
}