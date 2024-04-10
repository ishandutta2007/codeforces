#include<cstdio>
#include<algorithm>
using namespace std;
#define N 700050
int ch[N<<1][26],fail[N<<1],len[N<<1],sz[N<<1],las[N<<1],cnt=1,last=1,n,k,ecnt,s[N<<1],l=1;
char v[N];
void insert(int s)
{
	int st=++cnt,s1=last;len[st]=len[s1]+1;last=st;
	while(!ch[s1][s]&&s1)ch[s1][s]=st,s1=fail[s1];
	if(!s1)fail[st]=1;
	else
	{
		int tmp=ch[s1][s];
		if(len[tmp]==len[s1]+1)fail[st]=tmp;
		else
		{
			int cl=++cnt;len[cl]=len[s1]+1;sz[cl]=sz[tmp];las[cl]=las[tmp];
			for(int i=0;i<26;i++)ch[cl][i]=ch[tmp][i];
			fail[cl]=fail[tmp];fail[tmp]=fail[st]=cl;
			while(ch[s1][s]==tmp&&s1)ch[s1][s]=cl,s1=fail[s1];
		}
	}
	while(las[st]<ecnt&&st)las[st]=ecnt,sz[st]++,st=fail[st];
}
bool cmp(int a,int b){return len[a]<len[b];}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",v+l);
		while(v[l+1])l++;
		v[++l]='%';l++;
	}
	ecnt=1;l--;
	for(int i=1;i<=l;i++)
	{
		if(v[i]=='%')
		last=1,ecnt++;
		else
		insert(v[i]-'a');
	}
	for(int i=1;i<=cnt;i++)
	if(sz[i]>=k)sz[i]=len[i]-len[fail[i]];
	else sz[i]=0;
	for(int i=1;i<=cnt;i++)s[i]=i;
	sort(s+1,s+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)sz[s[i]]+=sz[fail[s[i]]];
	long long ans=0,st=1;
	for(int i=1;i<=l;i++)
	{
		if(v[i]=='%')
		st=1,printf("%lld ",ans),ans=0;
		else
		st=ch[st][v[i]-'a'],ans+=sz[st];
	}
}