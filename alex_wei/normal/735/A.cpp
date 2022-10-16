#include<bits/stdc++.h>
using namespace std;
//123
#define ll long long
int n,k,g,t;
string s;
int main()
{
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)
		if(s[i]=='G')g=i;
		else if(s[i]=='T')t=i;
	if(g>t)swap(g,t);
	if((t-g)%k)cout<<"NO",exit(0);
	for(int i=g+k;i<=t;i+=k)
		if(s[i]=='#')cout<<"NO",exit(0);
	cout<<"YES";
	return 0;
}