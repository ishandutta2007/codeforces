#include<bits/stdc++.h>
using namespace std;
string s;
int ans=1,c;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(i>0&&s[i]!=s[i-1])ans++,c=1;
		else{
			c++;
			if(c>5)ans++,c=1;
		}
	}
	cout<<ans;
	return 0;
}