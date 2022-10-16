#include<bits/stdc++.h>
using namespace std;
string s;
long long c[128],ans; 
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)c[s[i]]++;
	for(int i=0;i<128;i++)ans+=c[i]*c[i];
	cout<<ans;
	return 0;
}