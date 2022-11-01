#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)501)

int n,m;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	string s="",t="";
	for(int i=0;i<n/4+10;i++)s+='4',t+='5';
	s+='5';t+='5';
	cout<<s<<"\n"<<t<<"\n";
	return 0;
}