#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
const char mir[20]={'A','H','I','M','O','T','U','V','W','X','Y'};
int main(){
	int i,j;
	string s,t;
	cin>>s;
	t=s;
	reverse(t.begin(),t.end());
	for(i=0;i<s.size();i++){
		if(s[i]!=t[i]) break;
		for(j=0;j<11;j++){
			if(s[i]==mir[j]) break;
		}
		if(j==11) break;
	}
	if(i==s.size()) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}