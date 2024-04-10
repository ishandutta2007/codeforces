#include<cstdio>
#include<cstring>
int Test_num,len,mn,mx,t;
int l[1000002]={},r[1000002]={},ans[500002];
char s[500002];
inline int min(int a,int b)
{
	return a<b? a:b;
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline void dfs(int x,int y)
{
	while(l[x])--l[x],dfs(x-1,0);
	while(r[x])--r[x],dfs(x+1,1);
	ans[t]=y,--t;
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%s",s),mn=mx=t=len=strlen(s);
		for(int i=0,pre=len;i<len;++i)
		{
			if(s[i]=='1')++r[pre],++pre;
			else ++l[pre],--pre;
			mn=min(mn,pre),mx=max(mx,pre);
		}
		dfs(len,0);for(int i=1;i<=len;++i)printf("%d",ans[i]);
		puts("");for(int i=mn;i<=mx;++i)l[i]=r[i]=0;
	}
	return 0;
}