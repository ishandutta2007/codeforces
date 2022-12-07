#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
char s[3010];
int len;
bool check(int x)
{
	if(s[x]!=s[x+1]||s[x+1]!=s[x+2]) return true;
	return false;
}
bool qs(char c)
{
	if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u') return true;
	return false;
}
void work(int x)// 
{
	if(x>=len) return;
	for(int i=x;i<min(x+2,len);i++) printf("%c",s[i]);
	for(int i=x+2;i<len;i++)
	{
		bool ty=false,tyy=false;
		for(int j=i-2;j<=i;j++)
			if(!qs(s[j])){ty=true;break;}
		if(!ty&&check(i-2)){printf(" ");tyy=true;}
		if(tyy){work(i);return;}
		printf("%c",s[i]);
	}
}
int main()
{
	scanf("%s",s);
	len=strlen(s);
	work(0);
}