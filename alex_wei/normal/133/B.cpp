#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e6+3;
string s;
int ans,bs=1;
int main(){
	cin>>s;
	for(int i=s.size()-1;~i;i--){
		int t;
		if(s[i]=='>')t=8;
		if(s[i]=='<')t=9;
		if(s[i]=='+')t=10;
		if(s[i]=='-')t=11;
		if(s[i]=='.')t=12;
		if(s[i]==',')t=13;
		if(s[i]=='[')t=14;
		if(s[i]==']')t=15;
		ans=(ans+bs*t)%mod;
		bs=(bs<<4)%mod;
	}
	cout<<ans<<endl;
    return 0;
}