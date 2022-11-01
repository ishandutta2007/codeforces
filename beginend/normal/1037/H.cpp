#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,fa[N],ch[N][26],mx[N],b[N],c[N],rt[N],tot,sz,last,pos[N];
struct tree{int l,r;bool w;}t[N*30];
char s[N];

void extend(int x)
{
	int p,q,np,nq;
	p=last;last=np=++tot;mx[np]=mx[p]+1;
	for (;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
	if (!p) fa[np]=1;
	else
	{
		q=ch[p][x];
		if (mx[q]==mx[p]+1) fa[np]=q;
		else 
		{
			nq=++tot;mx[nq]=mx[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q];fa[q]=fa[np]=nq;
			for (;ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
		}
	}
}

void ins(int &d,int l,int r,int x)
{
	if (!d) d=++sz;
	t[d].w=1;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,l,mid,x);
	else ins(t[d].r,mid+1,r,x);
}

int merge(int x,int y)
{
	if (!x||!y) return x^y;
	int p=++sz;
	t[p].w=t[x].w|t[y].w;
	t[p].l=merge(t[x].l,t[y].l);
	t[p].r=merge(t[x].r,t[y].r);
	return p;
}

bool query(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return t[d].w;
	if (!t[d].w||x>y) return 0;
	int mid=(l+r)/2;
	if (x<=mid&&query(t[d].l,l,mid,x,y)) return 1;
	if (y>mid&&query(t[d].r,mid+1,r,x,y)) return 1;
	return 0;
}

void pre()
{
	for (int i=1;i<=tot;i++) b[mx[i]]++;
	for (int i=1;i<=tot;i++) b[i]+=b[i-1];
	for (int i=tot;i>=1;i--) c[b[mx[i]]--]=i;
	for (int i=1;i<=n;i++) ins(rt[pos[i]],1,n,i);
	for (int i=tot;i>1;i--) rt[fa[c[i]]]=merge(rt[fa[c[i]]],rt[c[i]]);
}

void solve()
{
	int l,r;scanf("%d%d%s",&l,&r,s+1);
	int m=strlen(s+1),now=1,lim=m;
	for (int i=1;i<=m;i++)
		if (ch[now][s[i]-'a']) now=ch[now][s[i]-'a'],pos[i]=now;
		else {lim=i-1;break;}
	pos[0]=1;
	for (int i=lim;i>=0;i--)
		for (int j=(i<m?s[i+1]-'a'+1:0);j<26;j++)
			if (query(rt[ch[pos[i]][j]],1,n,l+i,r))
			{
				for (int k=1;k<=i;k++) putchar(s[k]);
				putchar(j+'a');
				puts("");
				return;
			}
	puts("-1");
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	last=tot=1;
	for (int i=1;i<=n;i++) extend(s[i]-'a'),pos[i]=last;
	pre();
	int q;scanf("%d",&q);
	while (q--) solve();
	return 0;
}