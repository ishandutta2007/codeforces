#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,ans;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(i==0||s[i]==s[i-1])cnt++;
		else ans+=!(cnt%2),cnt=1;
	cout<<ans+!(cnt%2);
	return 0;
}