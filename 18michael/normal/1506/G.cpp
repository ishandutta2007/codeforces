#include<bits/stdc++.h>
using namespace std;
int Test_num,l,t;
int la[26],u[26];
char s[200002],ans[200002];
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%s",s+1),l=strlen(s+1),t=0;
		for(int i=0;i<26;++i)la[i]=u[i]=0;
		for(int i=1;i<=l;++i)la[s[i]-'a']=i;
		for(int i=1;i<=l;++i)
			if(!u[s[i]-'a'])
			{
				while(t && s[i]>ans[t] && i<la[ans[t]-'a'])u[ans[t]-'a']=0,--t;
				ans[++t]=s[i],u[s[i]-'a']=1;
			}
		for(int i=1;i<=t;++i)printf("%c",ans[i]);
		puts("");
	}
	return 0;
}