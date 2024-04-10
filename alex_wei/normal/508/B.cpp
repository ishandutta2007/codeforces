#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int eve;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++)eve+=s[i]%2==0;
	if(!eve)puts("-1"); 
	else{
		for(int i=0;i<s.size();i++){
			if(s[i]%2==0&&(s[i]<s[s.size()-1]||eve==1))swap(s[i],s[s.size()-1]),cout<<s,exit(0);
			eve-=s[i]%2==0;
		}
	}
	return 0;
}