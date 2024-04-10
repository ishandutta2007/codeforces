#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
string s;
int main(){
	cin>>t;
	while(t--){
		cin>>s;
		int h=0,t=0,pd=0,o=0;
		for(int i=0;i<s.size();i++)if(s[i]=='0')h++;else break;
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]=='0')t++;
			else{
				pd=1;
				break;
			}
		}
		for(int i=0;i<s.size();i++)o+=s[i]=='1';
		if(pd)cout<<s.size()-h-t-o<<endl;
		else cout<<0<<endl;
	}
	return 0;
}