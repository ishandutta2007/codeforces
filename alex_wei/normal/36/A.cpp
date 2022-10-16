#include<bits/stdc++.h>
using namespace std;
string s;
int n,ct,p[102];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>s;
	for(int i=0;i<n;i++)
		if(s[i]=='1')p[++ct]=i;
	for(int i=3;i<=ct;i++)
		if(p[i]-p[i-1]!=p[i-1]-p[i-2])cout<<"NO",exit(0);
	cout<<"YES";
	return 0;
}