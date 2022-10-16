#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s; int a;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++)a+=s[i]=='1';
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')cout<<'0';
		else if(s[i]=='2'){
			while(a)cout<<'1',a--;
			cout<<'2';
		}
	while(a)cout<<'1',a--;
    return 0;
}