#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,cnt,hav;
string s,q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		int pd=1,one=0;
		for(int j=0;j<s.size();j++){
			if(s[j]>'1'||one&&s[j]=='1'){pd=0;break;}
			if(s[j]=='1')one=1;
		}
		if(pd&&!one)puts("0"),exit(0);
		if(pd)cnt+=s.size()-1;
		else q=s,hav=1;
	}
	if(hav)cout<<q;
	else cout<<1;
	for(int i=1;i<=cnt;i++)cout<<'0';
    return 0;
}