#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 1000005;
char s1[maxn],s2[maxn],s[maxn];int dp[maxn],n,adj[maxn][26];
int qlink[maxn],dif[maxn],par[maxn],len[maxn],cur,tot,fr[maxn],ans[maxn];
int extend(int pos)
{
	int p=cur,ch=s[pos]-'a';
	while (s[pos]!=s[pos-len[p]-1]) p=par[p];
	if (!adj[p][ch]) {
		int q=++tot;len[q]=len[p]+2;
		int t=par[p];while (s[pos]!=s[pos-len[t]-1]) t=par[t];
		t=adj[t][ch];par[q]=t;dif[q]=len[q]-len[t];
		qlink[q]=dif[q]==dif[t]?qlink[t]:t;
		adj[p][ch]=q;
	}
	return adj[p][ch];
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("reverses.in","r",stdin);
	#endif
	scanf("%s %s",s1+1,s2+1);n=strlen(s1+1);
	for (int i=1;i<=n;i++)
		s[i*2-1]=s1[i],s[i<<1]=s2[i];
	
	cur=0;tot=1;par[0]=par[1]=1;len[1]=-1;
	for (int i=1;i<=n<<1;i++)
	{
		cur=extend(i);ans[i]=1<<30;
		for (int p=cur;p;p=qlink[p])
		{
			dp[p]=i-len[qlink[p]]-dif[p];
			if (qlink[p]!=par[p]&&ans[dp[par[p]]]<ans[dp[p]])
				dp[p]=dp[par[p]];
			if (i%2==0&&ans[dp[p]]+1<ans[i])
				ans[i]=ans[dp[p]]+1,fr[i]=dp[p];
		}
		if (i%2==0&&s[i]==s[i-1]&&ans[i-2]<ans[i])
			ans[i]=ans[i-2],fr[i]=i-2;
	}
	
	if (ans[n<<1]>n) puts("-1");
	else {
		printf("%d\n",ans[n<<1]);
		for (int p=n<<1;p;p=fr[p])
			if (fr[p]!=p-2) printf("%d %d\n",fr[p]/2+1,p/2);
	}
	return 0;
}