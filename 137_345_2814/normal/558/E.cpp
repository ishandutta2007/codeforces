#include<cstdio>
#pragma GCC optimize(2)
using namespace std;
struct ed{
	int d[27],l,r,lazy;
}e[400004];
char f[100002];
int cnt,n,m1,a,b,c;
void update(int m)
{
	for(int i=1;i<=26;i++)
	e[m].d[i]=e[m<<1].d[i]+e[m<<1|1].d[i];
}
inline void push(int m,int l)
{
	e[m<<1|1].lazy=e[m<<1].lazy=e[m].lazy;
	e[m].lazy=0;
	for(int i=1;i<=26;i++)
	e[m<<1].d[i]=e[m<<1|1].d[i]=0;
	if(e[m].l==e[m].r)
	return;
	int s=e[m<<1].r-e[m<<1].l+1;
	if(l==1)
	{
	for(int i=1;i<=26&&s;i++)
		if(e[m].d[i]<=s)
			e[m<<1].d[i]+=e[m].d[i],s-=e[m].d[i],e[m].d[i]=0;
		else
			e[m<<1].d[i]+=s,e[m].d[i]-=s,s=0;	
	}
	else
	{
	for(int i=26;i>0&&s;i--)
		if(e[m].d[i]<=s)
			e[m<<1].d[i]+=e[m].d[i],s-=e[m].d[i],e[m].d[i]=0;
		else
			e[m<<1].d[i]+=s,e[m].d[i]-=s,s=0;		
	}
	for(int i=1;i<=26;i++)
	e[m<<1|1].d[i]=e[m].d[i],e[m].d[i]+=e[m<<1].d[i];
//	update(m);
}
void build(int m,int l,int r)
{
	e[m].l=l;
	e[m].r=r;
	if(l==r)
	{
		e[m].d[f[++cnt]-'a'+1]++;
		return;
	}
	int mid=(l+r)>>1;
	build(m<<1,l,mid);
	build(m<<1|1,mid+1,r);
	update(m);
}
int ans[27];
void que(int m,int l,int r)
{
	if(e[m].l==l&&e[m].r==r)
	{
		for(int i=1;i<=26;i++)
		ans[i]+=e[m].d[i],e[m].d[i]=0;
		return;
	}
	if(e[m].lazy)
    push(m,e[m].lazy);
	int mid=(e[m].l+e[m].r)>>1;
	if(l>mid)
    que(m<<1|1,l,r);
    else
    if(r<=mid)
    que(m<<1,l,r);
    else
    {
        que(m<<1,l,mid);
        que(m<<1|1,mid+1,r);
    }
}
void add(int m,int l,int r)
{
	if(e[m].l==l&&e[m].r==r)
	{
		int t=e[m].r-e[m].l+1;
		for(int i=1;i<=26&&t;i++)
		if(ans[i]<t)
			e[m].d[i]+=ans[i],t-=ans[i],ans[i]=0;
		else
			e[m].d[i]+=t,ans[i]-=t,t=0;
		e[m].lazy=1;
		return;
	}
	if(e[m].lazy)
    push(m,e[m].lazy);
	int mid=(e[m].l+e[m].r)>>1;
	if(l>mid)
    add(m<<1|1,l,r);
    else
    if(r<=mid)
    add(m<<1,l,r);
    else
    {
        add(m<<1,l,mid);
        add(m<<1|1,mid+1,r);
    }
    update(m);
}
void add1(int m,int l,int r)
{
	if(e[m].l==l&&e[m].r==r)
	{
		int t=e[m].r-e[m].l+1;
		for(int i=26;i>0&&t;i--)
		if(ans[i]<t)
			e[m].d[i]+=ans[i],t-=ans[i],ans[i]=0;
		else
			e[m].d[i]+=t,ans[i]-=t,t=0;
		e[m].lazy=2;
		return;
	}
	if(e[m].lazy)
    push(m,e[m].lazy);
	int mid=(e[m].l+e[m].r)>>1;
	if(l>mid)
    add1(m<<1|1,l,r);
    else
    if(r<=mid)
    add1(m<<1,l,r);
    else
    {
        add1(m<<1,l,mid);
        add1(m<<1|1,mid+1,r);
    }
    update(m);
}
void que2(int m)
{
	if(e[m].l==e[m].r)
	{
		for(int i=1;i<=26;i++)
		if(e[m].d[i])
		{
			printf("%c",i+'a'-1);
			return;
		}
	}
	if(e[m].lazy)
    push(m,e[m].lazy);
	que2(m<<1);que2(m<<1|1);
}
int read()
{
	char s=getchar();
	int x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+s-'0',s=getchar();
	return x;
}
int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	scanf("%d%d",&n,&m1);
	scanf("%s",f+1);
	build(1,1,n);
	for(int i=1;i<=m1;i++)
	{
		a=read();
		b=read();
		c=read();
		que(1,a,b);
		if(c==1)
		add(1,a,b);
		else
		add1(1,a,b);
	}
	que2(1);
//	for(int i=1;i<=n;i++)
//	printf("%c",que2(1,i)+'a'-1);
//	fclose(stdin);
//	fclose(stdout);
}