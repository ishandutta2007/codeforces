#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,now=1,t=1;
typedef pair<int,int> P;
P f[1000002],g[1000002];
char s[1000002];
struct aaa
{
	int fail,len,dif,top;
	int to[26];
}p[1000002];
int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=n;i;--i)s[(i<<1)-1]=s[i];
	n<<=1;
	for(int i=2;i<=n;i+=2)do s[i]=getchar();while(s[i]<'a' || s[i]>'z');
	p[0].fail=p[0].dif=p[0].top=1,p[1].len=-1,g[0]=g[1]=P(inf,0);
	for(int i=1,j,c;i<=n;++i)
	{
		for(c=s[i]-'a';s[i]^s[i-p[now].len-1];now=p[now].fail);
		if(!p[now].to[c])
		{
			for(p[now].to[c]=(++t),p[t].len=p[now].len+2,j=p[now].fail;s[i]^s[i-p[j].len-1];j=p[j].fail);
			if(p[j].to[c]^t)p[t].fail=p[j].to[c];
			p[t].dif=p[t].len-p[p[t].fail].len,p[t].top=(p[t].dif==p[p[t].fail].dif? p[p[t].fail].top:p[t].fail);
		}
		for(f[i]=((i&1 || s[i]^s[i-1])? P(inf,0):P(f[i-2].first,i-2)),j=now=p[now].to[c];j^1;j=p[j].top)
		{
			g[j]=P(f[i-p[p[j].top].len-p[j].dif].first,i-p[p[j].top].len-p[j].dif);
			if(p[j].top^p[j].fail)g[j]=min(g[j],g[p[j].fail]);
			if(!(i&1) && g[j].first+1<f[i].first)f[i]=P(g[j].first+1,g[j].second);
		}
	}
	if(f[n].first==inf)return 0&puts("-1");
	for(printf("%d\n",f[n].first);n;n=f[n].second)if(f[n].second+2<n)printf("%d %d\n",(f[n].second>>1)+1,(n>>1));
	return 0;
}