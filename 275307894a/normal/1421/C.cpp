#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,flag,ans;
char s[100039];
int main(){
	cin>>s+1;
	n=strlen(s+1);
	if(s[1]!=s[3]) printf("3\nL 2\n"),flag=1;
	else printf("2\n");
	printf("R 2\nR %d\n",2*n-3+flag*2);
}