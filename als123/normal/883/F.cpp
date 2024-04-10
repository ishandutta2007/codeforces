#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int n;
char s1[45];
int s[410][45];
int cnt[410];
bool check[410];
bool same(int a,int b)
{
	if(cnt[a]!=cnt[b]) return false;
	for(int i=1;i<=cnt[a];i++) if(s[a][i]!=s[b][i]) return false;
	return true;
}
bool solve(int x)
{
	for(int i=1;i<x;i++)
		if(check[i]&&same(i,x)) return false;
	return true;
}
int main()
{
	scanf("%d",&n);getchar();
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
	{
		int last=-1;
		scanf("%s",s1+1);int len=strlen(s1+1);int p=1;
		while(p<=len)
		{
			char ch=s1[p];
			if(ch=='k')
			{
				if(last==-1) last=cnt[i];
				s[i][++cnt[i]]=ch-'a'+1;
			}
			else
			{
				if(ch=='h'&&last!=-1) cnt[i]=last;
				last=-1;
				if(ch=='u') ch='o',s[i][++cnt[i]]=ch-'a'+1;
				s[i][++cnt[i]]=ch-'a'+1;
			}
			p++;
		}
		//printf("fi:");for(int j=1;j<=cnt[i];j++) printf("%c",s[i][j]+'a'-1);printf("\n");
	}
	int ans=0;
	memset(check,false,sizeof(check));
	for(int i=1;i<=n;i++)
		if(solve(i)) check[i]=true,ans++;
	printf("%d",ans);
}
/*
10
mihail
oolyana
kooooper
hoon
ulyana
koouper
mikhail
khun
kuooper
kkkhoon
*/