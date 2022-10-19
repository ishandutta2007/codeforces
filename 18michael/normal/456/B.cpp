#include<cstdio>
#include<cstring>
int x,len;
char ch[100002];
int main()
{
	scanf("%s",ch+1),len=strlen(ch+1),x=(ch[len]^48);
	if(len>1)x+=(ch[len-1]^48)*10;
	return 0&puts((x%4)? "0":"4");
}