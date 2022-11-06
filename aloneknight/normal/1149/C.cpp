#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,Q,m;char s[N];
struct st
{
	int p=0,m=0,lm=0,mr=0,d=0,tg=0;
	inline void upd(int v){p+=v;m-=2*v;lm-=v;mr-=v;tg+=v;}
	inline st operator+(const st&b)const
	{
		st c;c.p=max(p,b.p);c.m=max(m,b.m);
		c.lm=max(max(lm,b.lm),p+b.m);c.mr=max(max(mr,b.mr),m+b.p);
		c.d=max(max(d,b.d),max(lm+b.p,p+b.mr));return c;
	}
}T[N<<2];
void upd(int x,int l,int r,int tl,int tr,int v)
{
	if(r<tl||tr<l)return;if(tl<=l&&r<=tr){T[x].upd(v);return;}
	T[x<<1].upd(T[x].tg);T[x<<1|1].upd(T[x].tg);T[x].tg=0;int mid=l+r>>1;
	upd(x<<1,l,mid,tl,tr,v);upd(x<<1|1,mid+1,r,tl,tr,v);T[x]=T[x<<1]+T[x<<1|1];
}
int main()
{
	scanf("%d%d%s",&n,&Q,s+1);m=2*n-2;
	for(int i=1;i<=m;i++)if(s[i]=='(')upd(1,1,m,i,m,1);else upd(1,1,m,i,m,-1);
	printf("%d\n",T[1].d);
	while(Q--)
	{
		int a,b;scanf("%d%d",&a,&b);
		if(s[a]!=s[b])
		{
			if(s[a]=='(')upd(1,1,m,a,m,-2);else upd(1,1,m,a,m,2);
			if(s[b]=='(')upd(1,1,m,b,m,-2);else upd(1,1,m,b,m,2);
			swap(s[a],s[b]);
		}
		printf("%d\n",T[1].d);
	}
	return 0;
}