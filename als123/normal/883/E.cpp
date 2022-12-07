#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
bool check[30],t[30];
int ans[30];
int n,m,num=0;
char s[55],s1[55];
int main()
{
	scanf("%d",&n);getchar();
	memset(check,false,sizeof(check));
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(s[i]!='*') check[s[i]-'a'+1]=true;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s1+1);
		bool flag=false;
		for(int j=1;j<=n;j++)
		{
			if(check[s1[j]-'a'+1]&&s[j]=='*') flag=true;
			if(!check[s1[j]-'a'+1]&&s[j]!='*') flag=true;
		}
		if(flag) continue;
		num++;
		memset(t,false,sizeof(t));
		for(int j=1;j<=n;j++)
			if(!check[s1[j]-'a'+1]&&!t[s1[j]-'a'+1])
				ans[s1[j]-'a'+1]++,t[s1[j]-'a'+1]=true;
	}
	int Ans=0;
	for(int i=1;i<=26;i++) if(ans[i]==num) Ans++;
	printf("%d\n",Ans);
}