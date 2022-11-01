#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=100005;
const int M=325;

int n,m,block,bel[N],sta[M],end[M],h[M][N],f[N],s[N],a[N],val[N],mx[M],tag[M];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

void updata(int id)
{
	while (!h[id][mx[id]]) mx[id]--;
}

void build(int id)
{
	int l=sta[id],r=end[id];
	for (int i=l;i<=r;i++) a[i]=val[find(i)],h[id][a[i]]=0;
	for (int i=l;i<=r;i++) f[i]=i,s[i]=1;
	for (int i=l;i<=r;i++)
		if (h[id][a[i]]) s[h[id][a[i]]]+=s[i],f[i]=h[id][a[i]];
		else h[id][a[i]]=i,val[i]=a[i];
	updata(id);
}

void change(int id,int l,int r,int x)
{
	for (int i=sta[id];i<=end[id];i++) a[i]=val[find(i)];
	for (int i=sta[id];i<=end[id];i++) h[id][a[i]]=0;
	for (int i=l;i<=r;i++) if (a[i]-tag[id]>x) a[i]-=x;
	for (int i=sta[id];i<=end[id];i++) val[i]=a[i],f[i]=i;
	build(id);
}

void modify(int l,int r,int x)
{
	if (bel[l]==bel[r]) {change(bel[l],l,r,x);return;}
	change(bel[l],l,end[bel[l]],x);
	change(bel[r],sta[bel[r]],r,x);
	for (int i=bel[l]+1;i<bel[r];i++)
		if (x*2<=mx[i]-tag[i])
		{
			for (int j=tag[i]+1;j<=tag[i]+x;j++)
				if (h[i][j])
				{
					if (!h[i][j+x]) h[i][j+x]=h[i][j],val[h[i][j]]=j+x,h[i][j]=0;
					else s[h[i][j+x]]+=s[h[i][j]],f[h[i][j]]=h[i][j+x],h[i][j]=0;
				}
			tag[i]+=x;
		}
		else
		{
			for (int j=tag[i]+x+1;j<=mx[i];j++)
				if (h[i][j])
				{
					if (!h[i][j-x]) h[i][j-x]=h[i][j],val[h[i][j]]=j-x,h[i][j]=0;
					else s[h[i][j-x]]+=s[h[i][j]],f[h[i][j]]=h[i][j-x],h[i][j]=0;
				}
			updata(i);
		}
}

int query(int l,int r,int x)
{
	int ans=0;
	if (bel[l]==bel[r])
	{
		for (int i=l;i<=r;i++) if (val[find(i)]-tag[bel[l]]==x) ans++;
		return ans;
	}
	for (int i=l;i<=end[bel[l]];i++) if (val[find(i)]-tag[bel[l]]==x) ans++;
	for (int i=sta[bel[r]];i<=r;i++) if (val[find(i)]-tag[bel[r]]==x) ans++;
	for (int i=bel[l]+1;i<bel[r];i++) if (x+tag[i]<=100000) ans+=s[h[i][x+tag[i]]];
	return ans;
}

int main()
{
	n=read();m=read();block=sqrt(n);
	for (int i=1;i<=n;i++)
	{
		a[i]=val[i]=read();f[i]=i;
		bel[i]=(i+block-1)/block;
		end[bel[i]]=i;
		if (!sta[bel[i]]) sta[bel[i]]=i;
	}
	for (int i=1;i<=bel[n];i++) mx[i]=100000,build(i);
	while (m--)
	{
		int op=read(),l=read(),r=read(),x=read();
		if (op==1) modify(l,r,x);
		else printf("%d\n",query(l,r,x));
	}
	return 0;
}