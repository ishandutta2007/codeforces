#include<bits/stdc++.h>
using namespace std;
string s,t;
int l,r=1,ans;
int main()
{
	cin>>s>>t,l=t.size();
	while(l>1||r<=s.size()){
		int c=0;
		for(int i=0;i+l<=t.size()&&i+r<=s.size();i++)
			c+=s[r+i-1]==t[l+i-1];
		ans=max(ans,c);
		if(l>1)l--;
		else r++;
	}
	cout<<t.size()-ans;
	return 0;
}