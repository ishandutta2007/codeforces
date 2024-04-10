#include<bits/stdc++.h>

const int N=400005;

int n,q,last[N*2],pos[N],tim,dfn[N*2],mx[N*2],cnt,ch[N*2][26],fail[N*2],sz,tot,rt[N*2];
bool exi[N*2][26];
struct edge{int to,next;}e[N*2];
struct tree{int l,r,s;}t[N*50];
struct data{int x,y;}a[N];
std::queue<int> que;
char str[N];

int ins()
{
	int l=strlen(str),now=0;
	for (int i=0;i<l;i++)
	{
		int *p=&ch[now][str[i]-'a'];
		if (!(*p)) *p=++tot;
		now=*p;
	}
	return now;
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void dfs(int x)
{
	dfn[x]=++tim;
	for (int i=last[x];i;i=e[i].next) dfs(e[i].to);
	mx[x]=tim;
}

void ins(int &d,int l,int r,int x)
{
	int p=d;d=++sz;t[d]=t[p];
	t[d].s++;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,l,mid,x);
	else ins(t[d].r,mid+1,r,x);
}

int query(int d,int l,int r,int x,int y)
{
	if (!d||x<=l&&r<=y) return t[d].s;
	int mid=(l+r)/2;
	if (y<=mid) return query(t[d].l,l,mid,x,y);
	else if (x>mid) return query(t[d].r,mid+1,r,x,y);
	else return query(t[d].l,l,mid,x,y)+query(t[d].r,mid+1,r,x,y);
}

void build()
{
	for (int i=0;i<26;i++) if (ch[0][i]) que.push(ch[0][i]);
	while (!que.empty())
	{
		int x=que.front();que.pop();
		addedge(fail[x],x);
		for (int i=0;i<26;i++)
			if (!ch[x][i]) ch[x][i]=ch[fail[x]][i],exi[x][i]=1;
			else que.push(ch[x][i]),fail[ch[x][i]]=ch[fail[x]][i];
	}
	dfs(0);
	for (int i=0;i<=tot;i++)
		for (int j=0;j<26;j++)
			if (!exi[i][j]&&ch[i][j]) rt[ch[i][j]]=rt[i],ins(rt[ch[i][j]],1,tim,dfn[ch[i][j]]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int op,fa=0;scanf("%d",&op);
		if (op==2) scanf("%d",&fa),fa=pos[fa];
		scanf("%s",str);
		if (!ch[fa][str[0]-'a']) ch[fa][str[0]-'a']=++tot;
		pos[i]=ch[fa][str[0]-'a'];
	}
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%s",&a[i].x,str);
		a[i].y=ins();
	}
	build();
	for (int i=1;i<=q;i++) printf("%d\n",query(rt[pos[a[i].x]],1,tim,dfn[a[i].y],mx[a[i].y]));
	return 0;
}