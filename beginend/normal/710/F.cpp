#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

typedef long long LL; 

const int N=300005;

int m,len;
char str[N];
std::queue<int> que;

struct ACAM
{
	int sz,cnt[N],ch[N][26],ac[N][26],rt[25],sum[N],fail[N],t[25];
	
	void add(int &d,int x)
	{
		if (!d) d=++sz;
		if (x>len) {cnt[d]++;return;}
		add(ch[d][str[x]-'a'],x+1);
	}
	
	int merge(int x,int y)
	{
		if (!x||!y) return x^y;
		cnt[x]+=cnt[y];
		for (int i=0;i<26;i++) ch[x][i]=merge(ch[x][i],ch[y][i]);
		return x;
	}
	
	void build(int d)
	{
		que.push(d);fail[d]=d;sum[d]=0;
		for (int i=0;i<26;i++) ac[d][i]=d;
		while (!que.empty())
		{
			int u=que.front();que.pop();
			sum[u]=sum[fail[u]]+cnt[u];
			for (int i=0;i<26;i++)
				if (ch[u][i])
				{
					int v=ch[u][i];
					que.push(v);
					fail[v]=ac[fail[u]][i]; 
					ac[u][i]=v;
				}
				else ac[u][i]=ac[fail[u]][i];
		}
	}
	
	void ins()
	{
		add(rt[0],1);
		int i;
		for (i=0;t[i]==1;i++)
		{
			rt[i+1]=merge(rt[i],rt[i+1]);
			t[i]^=1;
			rt[i]=0;
		}
		t[i]^=1;
		build(rt[i]);
	}
	
	LL calc()
	{
		LL ans=0;
		for (int i=0;i<=20;i++)
		{
			if (!rt[i]) continue;
			int x=rt[i];
			for (int j=1;j<=len;j++)
			{
				x=ac[x][str[j]-'a'];
				ans+=sum[x];
			}
		}
		return ans;
	}
}ac1,ac2;

int main()
{
	scanf("%d",&m);
	while (m--)
	{
		int op;scanf("%d%s",&op,str+1);
		len=strlen(str+1);
		if (op==1) ac1.ins();
		else if (op==2) ac2.ins();
		else printf("%lld\n",ac1.calc()-ac2.calc()),fflush(stdout);
	}
	return 0;
}