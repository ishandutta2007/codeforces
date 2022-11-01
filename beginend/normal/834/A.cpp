#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	char ch1[2],ch2[2];
	scanf("%s%s",ch1,ch2);
	int x,y;
	if (ch1[0]=='^') x=0;
	else if (ch1[0]=='>') x=1;
	else if (ch1[0]=='v') x=2;
	else x=3;
	if (ch2[0]=='^') y=0;
	else if (ch2[0]=='>') y=1;
	else if (ch2[0]=='v') y=2;
	else y=3;
	int n;
	scanf("%d",&n);
	n%=4;
	if ((x+n)%4==y&&(x-n+4)%4!=y) puts("cw");
	else if ((x+n)%4!=y&&(x-n+4)%4==y) puts("ccw");
	else puts("undefined");
	return 0;
}