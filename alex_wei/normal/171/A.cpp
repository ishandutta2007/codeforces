#include<bits/stdc++.h>
using namespace std;
string s,t;
int p[12],pd; 
int main()
{
	cin>>s>>t;
	reverse(t.begin(),t.end());
	if(t.size()>s.size())swap(s,t);
	for(int i=1;i<=t.size();i++)
		p[i]+=s[s.size()-i]+t[t.size()-i]-96,p[i+1]+=p[i]/10,p[i]%=10;
	for(int i=t.size()+1;i<=s.size();i++)
		p[i]+=s[s.size()-i]-48,p[i+1]+=p[i]/10,p[i]%=10;
	for(int i=s.size()+1;i>0;i--)
		if(pd||p[i]||i==1)
			cout<<p[i],pd=1;
	return 0;
}