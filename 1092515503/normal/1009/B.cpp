#include<bits/stdc++.h>
using namespace std;
char s[100100];
int n,c0,c1,tc0;
vector<int>v;
int main(){
	scanf("%s",s),n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]=='0')c0++;
		if(s[i]=='1')c1++;
		if(s[i]=='2'){
			if(!v.empty())v[v.size()-1]=c0;
			else tc0=c0;
			c0=0;
			v.push_back(0);
		}
	}
	if(!v.empty())v[v.size()-1]=c0;
	else tc0=c0;
	for(int i=0;i<tc0;i++)putchar('0');
	for(int i=0;i<c1;i++)putchar('1');
	for(int i=0;i<v.size();i++){
		putchar('2');
		for(int j=0;j<v[i];j++)putchar('0');
	}
	return 0;
}