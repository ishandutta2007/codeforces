#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,cnt=0;
string s;
int main()
{
	cin>>n>>k>>s;
	if(s.size()==1){
		if(k>0||s[0]=='0')cout<<0,exit(0);
		else cout<<s[0],exit(0);
	}
	for(int i=0;i<s.size();i++){
		if(cnt>=k)break;
		if(i==0&&s[i]>'1')cnt++,s[i]='1';
		else if(i>0&&s[i]>'0')cnt++,s[i]='0';
	}
	cout<<s;
    return 0;
}