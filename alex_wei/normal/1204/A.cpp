#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,t;
int pd=1;
bool cmp(string a,string b)
{
	if(a.size()<b.size())return false;
	if(a.size()>b.size())return true;
	for(int i=0;i<a.size();i++){
		if(a[i]>b[i])return true;
		if(a[i]<b[i])return false;
	}
	return false;
}
int main()
{
	cin>>s,t+='1';
	for(int i=0;i<1000;i++){
		if(!cmp(s,t))cout<<i,exit(0);
		t+="00";
	}
	return 0;
}