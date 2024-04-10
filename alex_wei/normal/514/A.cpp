#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(i==0&&s[i]=='9')cout<<9;
		else cout<<min(s[i],(char)('9'-s[i]+'0'));
	}
	return 0;
}