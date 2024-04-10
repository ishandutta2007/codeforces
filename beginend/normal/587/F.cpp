#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

typedef long long LL;

const int N=100005;
const int M=405;

int n,q,cnt,last[N],sz,ch[N][26],fa[N],fail[N],tim,bel[N],B,dfn[N],mx[N],sta[M],end[M],pre[N],id[N],tag[M],len[N],tot;
LL ans[N],s[N],t[N];
queue<int> que;
struct data{int x,k,c,id;}a[N*2];
vector<data> vec[N];
struct edge{int to,next;}e[N];
char str[N];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void get_fail()
{
	for (int i=0;i<26;i++) if (ch[0][i]) que.push(ch[0][i]);
	while (!que.empty())
	{
		int u=que.front();que.pop();
		addedge(fail[u]+1,u+1);
		for (int i=0;i<26;i++)
			if (ch[u][i]) fail[ch[u][i]]=ch[fail[u]][i],que.push(ch[u][i]);
			else ch[u][i]=ch[fail[u]][i];
	}
}

void dfs(int x)
{
	dfn[x]=++tim;
	for (int i=last[x];i;i=e[i].next) dfs(e[i].to);
	mx[x]=tim;
}

bool cmp(data a,data b) {return a.x<b.x;}

void solve(int x)
{
	for (int i=1;i<=sz;i++) s[i]=0;
	int tmp=id[x];
	while (tmp>1) s[dfn[tmp]]++,tmp=fa[tmp];
	for (int i=1;i<=sz;i++) s[i]+=s[i-1];
	for (int i=1;i<=n;i++) t[i]=t[i-1]+s[mx[id[i]]]-s[dfn[id[i]]-1];
	for (int i=0;i<vec[x].size();i++) ans[vec[x][i].id]+=(LL)vec[x][i].c*t[vec[x][i].x];
}

void add(int x,int y)
{
	if (x>sz) return;
	for (int i=bel[x]+1;i<=bel[sz];i++) tag[i]+=y;
	for (int i=x;i<=end[bel[x]];i++) pre[i]+=y;
}

int query(int x)
{
	return tag[bel[x]]+pre[x];
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",str);
		len[i]=strlen(str);int now=0;
		for (int j=0;j<len[i];j++)
			if (!ch[now][str[j]-'a']) ch[now][str[j]-'a']=++sz,fa[sz+1]=now+1,now=sz;
			else now=ch[now][str[j]-'a'];
		id[i]=now+1;
	}
	get_fail();sz++;
	B=sqrt(sz);dfs(1);
	for (int i=1;i<=sz;i++)
	{
		bel[i]=(i+B-1)/B;end[bel[i]]=i;
		if (!sta[bel[i]]) sta[bel[i]]=i;
	}
	for (int i=1;i<=q;i++)
	{
		int l,r,k;scanf("%d%d%d",&l,&r,&k);
		if (len[k]>B)
		{
			if (l-1) vec[k].push_back((data){l-1,k,-1,i});
			vec[k].push_back((data){r,k,1,i});
		}
		else
		{
			if (l-1) a[++tot]=(data){l-1,k,-1,i};
			a[++tot]=(data){r,k,1,i};
		}
	}
	for (int i=1;i<=n;i++) if (len[i]>B) solve(i);
	sort(a+1,a+tot+1,cmp);
	int now=1;
	for (int i=1;i<=n;i++)
	{
		add(dfn[id[i]],1);add(mx[id[i]]+1,-1);
		while (now<=tot&&a[now].x==i)
		{
			int tmp=id[a[now].k];
			while (tmp>1) ans[a[now].id]+=(LL)a[now].c*query(dfn[tmp]),tmp=fa[tmp];
			now++;
		}
	}
	for (int i=1;i<=q;i++) printf("%I64d\n",ans[i]);
	return 0;
}