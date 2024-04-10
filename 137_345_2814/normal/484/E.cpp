#include<cstdio>
#include<algorithm>
using namespace std;
int n,s1[100001],s2[100001],s3[100001],q,a,b,c;
int cnt,ecnt,rt[100001<<5],l[100001<<5],r[100001<<5],ls[100001<<5],rs[100001<<5],l1[100001<<5],r1[100001<<5],ans[100001<<5];
inline int Max(int a,int b){return a>b?a:b;}
void pushup(int x)
{
	ans[x]=Max(Max(ans[ls[x]],ans[rs[x]]),r1[ls[x]]+l1[rs[x]]);
	if(l1[ls[x]]==r[ls[x]]-l[ls[x]]+1)
	l1[x]=l1[ls[x]]+l1[rs[x]];
	else
	l1[x]=l1[ls[x]];
	if(r1[rs[x]]==r[rs[x]]-l[rs[x]]+1)
	r1[x]=r1[ls[x]]+r1[rs[x]];
	else
	r1[x]=r1[rs[x]];
}
int build(int lb,int rb)
{
	int st=++cnt;
	l[st]=lb;
	r[st]=rb;
	l1[st]=r1[st]=ans[st]=rb-lb+1;
	if(rb==lb)return st;
	int mid=(lb+rb)>>1;
	ls[st]=build(lb,mid);
	rs[st]=build(mid+1,rb);
	return st;
}
void add(int x,int y)
{
	if(l[x]==r[x]&&l[x]==y)
	{
		l1[x]=r1[x]=ans[x]=0;
		return;
	}
	int mid=(l[x]+r[x])>>1;
	if(mid>=y)
	{
		int st=++cnt;
		l[st]=l[ls[x]];
		r[st]=r[ls[x]];
		ls[st]=ls[ls[x]];
		rs[st]=rs[ls[x]];
		l1[st]=l1[ls[x]];
		r1[st]=r1[ls[x]];
		ans[st]=ans[ls[x]];
		ls[x]=st;
		add(st,y);
	}
	else
	{
		int st=++cnt;
		l[st]=l[rs[x]];
		r[st]=r[rs[x]];
		ls[st]=ls[rs[x]];
		rs[st]=rs[rs[x]];
		l1[st]=l1[rs[x]];
		r1[st]=r1[rs[x]];
		ans[st]=ans[rs[x]];
		rs[x]=st;
		add(st,y);
	}
	pushup(x);
}
void adds(int s)
{
	rt[++ecnt]=++cnt;
	l[cnt]=l[rt[ecnt-1]];
	r[cnt]=r[rt[ecnt-1]];
	ls[cnt]=ls[rt[ecnt-1]];
	rs[cnt]=rs[rt[ecnt-1]];
	l1[cnt]=l1[rt[ecnt-1]];
	r1[cnt]=r1[rt[ecnt-1]];
	ans[cnt]=ans[rt[ecnt-1]];
	add(cnt,s);
}
struct que{int a,b,c;};
que query(int x,int lb,int rb)
{
	if(l[x]==lb&&r[x]==rb||(l[x]==r[x]))
	return (que){l1[x],r1[x],ans[x]};
	int mid=(l[x]+r[x])>>1;
	if(mid>=rb)
	return query(ls[x],lb,rb);
	else
	if(mid<lb)
	return query(rs[x],lb,rb);
	else
	{
		que s1=query(ls[x],lb,mid),s2=query(rs[x],mid+1,rb),s3;
		s3.c=Max(Max(s1.c,s2.c),s1.b+s2.a);
		if(s1.a==mid-lb+1)
		s3.a=s1.a+s2.a;
		else
		s3.a=s1.a;
		if(s2.b==rb-mid)
		s3.b=s2.b+s1.b;
		else
		s3.b=s2.b;
		return s3;
	}
}
bool cmp(int i,int j){return s1[i]<s1[j];}
inline int read()
{
	char c=getchar();
	int ans=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	s1[i]=read(),s2[i]=i;
	sort(s2+1,s2+n+1,cmp);
	for(int i=1;i<=n;i++)
	s3[s2[i]]=i;
	rt[ecnt=1]=build(1,n);
	for(int i=1;i<n;i++)
	adds(s2[i]);
	sort(s1+1,s1+n+1);
	int tmp=0;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		a=read(),b=read(),c=read();
		int lb=1,rb=n,ans;
		while(lb<=rb)
		{
			int mid=(lb+rb)>>1;
			if(query(rt[mid],a,b).c>=c)
			ans=mid,lb=mid+1;
			else
			rb=mid-1;
		}
		printf("%d\n",s1[ans]);
	}
}