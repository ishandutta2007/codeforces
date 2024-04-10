#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int x,y;
string s; 
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++)x+=s[i]=='x',y+=s[i]=='y';
	if(x>=y)for(int i=0;i<x-y;i++)cout<<'x';
	else for(int i=0;i<y-x;i++)cout<<'y';
	return 0;
}