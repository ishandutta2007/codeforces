/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
char l[1000005],r[1000005];
int main(){
	scanf("%d%s%s",&n,l+1,r+1);
	if(l[1]!=r[1])for(int i=0;i<n;i++)cout<<'1';
	else if((r[n]&1)||n==1)cout<<r+1;
	else{
		l[n-1]++;
		for(int i=n-1;i;i--)if(l[i]>'1')l[i]='0',l[i-1]++;
		for(int i=0;i<=n+1;i++)if(l[i]!=r[i]||i>n)r[n]=(l[i]<r[i]||i>n)+'0',cout<<r+1,exit(0);
	}
	return 0;
}