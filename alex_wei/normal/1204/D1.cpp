#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,t;
int zero;
int main()
{
	cin>>s;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='0')zero++,t+='0';
		else if(zero)zero--,t+='1';
		else t+='0';
	}
	reverse(t.begin(),t.end());
	cout<<t;
	return 0;
}