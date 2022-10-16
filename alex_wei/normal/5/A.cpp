#include<bits/stdc++.h>
using namespace std;
string s;
int ans,p; 
int main()
{
	while(getline(cin,s)){
		if(s[0]=='-')
			p--;
		else if(s[0]=='+')
			p++;
		else ans+=p*(s.size()-s.find(':')-1);
	}
	cout<<ans;
	return 0;
}