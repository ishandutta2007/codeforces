#include<bits/stdc++.h>
using namespace std;
char s[10],t[10];
int main(){
	int d;
	scanf("%d %s %s",&d,s,t);
	if(strcmp(t,"week")==0){
		if(d==5||d==6) puts("53");
		else puts("52");
	}
	else{
		if(d<=29) puts("12");
		else if(d<=30) puts("11");
		else puts("7");
	}
	return 0;
}