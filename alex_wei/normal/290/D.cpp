#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main()
{
	cin>>s>>n;
	for(int i=0;i<s.size();i++){
		if(s[i]<'a')
			s[i]+=32;
		if(s[i]<'a'+n)
			cout<<(char)(s[i]-32);
		else cout<<s[i];
	}
    return 0;
}