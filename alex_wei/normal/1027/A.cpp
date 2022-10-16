#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
void work()
{
	for(int i=0;i<=s.size()/2;i++)
		if(abs(s[i]-s[s.size()-i-1])>2||abs(s[i]-s[s.size()-i-1])==1){cout<<"NO\n";return;}
	cout<<"YES\n";
}
int main()
{
	cin>>t;
	for(int i=0;i<t;i++)
		cin>>n>>s,work();
	return 0;
}