#include<bits/stdc++.h>
using namespace std;
int ans;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		for(int j=i+1;j<s.size();j++)
			for(int k=j+1;k<s.size();k++)
				if(s[i]=='Q'&&s[j]=='A'&&s[k]=='Q')ans++;
	cout<<ans;
    return 0;
}