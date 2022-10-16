#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,f,l;
string s; 
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
		if(s[i]!='4'&&s[i]!='7')cout<<"NO",exit(0);
		else i<n/2?f+=(s[i]^48):l+=(s[i]^48);
	f!=l?cout<<"NO":cout<<"YES";
	return 0;
}