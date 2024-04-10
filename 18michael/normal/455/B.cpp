#include<cstdio>
#include<cstring>
int n,k,len,now,trie_t=0;
int f[100002]={};
char s[100002];
struct aaa
{
	int to[26];
}trie[100002]={};
inline void dfs(int x)
{
	bool t=0;
	for(int i=0;i<26;++i)
		if(trie[x].to[i])
			dfs(trie[x].to[i]),f[x]|=f[trie[x].to[i]],t=1;
	if(!t)f[x]=1;
	else f[x]^=3;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s),len=strlen(s),now=0;
		for(int j=0;j<len;++j)
		{
			if(!trie[now].to[s[j]-'a'])trie[now].to[s[j]-'a']=(++trie_t);
			now=trie[now].to[s[j]-'a'];
		}
	}
	dfs(0),f[0]^=3;
	if(f[0]==3)puts("First");
	else if(!f[0])puts("Second");
	else puts(((k&1) && f[0]==1)? "First":"Second");
	return 0;
}