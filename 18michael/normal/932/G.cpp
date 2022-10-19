#include<cstdio>
#include<cstring>
#define mod 1000000007
int l,l1,p_t=1,las=0;
int f[1000002]={},g[1000002];
char s[1000002],s1[1000002];
struct aaa
{
	int len,fail,dif,top;
	int to[26];
}p[1000002]={};
inline void init()
{
	scanf("%s",s1+1),l=strlen(s1+1),l1=l/2,p[0].len=0,p[1].len=-1,p[0].fail=p[1].fail=p[0].top=p[1].top=1,f[0]=1;
	for(int i=1;i<=l1;++i)s[2*i-1]=s1[i],s[2*i]=s1[l+1-i];
	for(int i=1,j,c;i<=l;++i)
	{
		for(c=s[i]-'a';las!=1 && ((j=i-p[las].len-1)<=0 || s[i]!=s[j]);las=p[las].fail);
		if(p[las].to[c])las=p[las].to[c];
		else
		{
			p[p[las].to[c]=(++p_t)].len=p[las].len+2;
			while((las=p[las].fail)!=1 && ((j=i-p[las].len-1)<=0 || s[i]!=s[j]));
			if(p[las].to[c]==p_t)p[p_t].fail=0;else p[p_t].fail=p[las].to[c];
			las=p_t,p[p_t].dif=p[p_t].len-p[p[p_t].fail].len;
			if(p[p_t].dif==p[p[p_t].fail].dif)p[p_t].top=p[p[p_t].fail].top;
			else p[p_t].top=p[p_t].fail;
		}
		for(j=las;j!=1;j=p[j].top)
		{
			g[j]=f[i-p[p[j].top].len-p[j].dif];
			if(p[j].top!=p[j].fail)g[j]=(g[j]+g[p[j].fail])%mod;
			if(!(i&1))f[i]=(f[i]+g[j])%mod;
		}
	}
}
int main()
{
	init(),printf("%d",f[l]);
	return 0;
}