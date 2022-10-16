#include<cstdio>
#include<cstring>
#define lowbit(x)(x&-x)
char s[111111],t[22];
int flt[128];
int tree[11][11][4][100001];
int q,l;
inline void __change(int m,int rst,int c,register int r,int d)
{
	if(!r)return;
	for(;r<=l;r+=lowbit(r))tree[m][rst][c][r]+=d;
}
inline void modify(int p,char c)
{
	register int i;
	for(i=1;i<=10;i++)
		__change(i,p%i,flt[s[p]],p,-1);
	for(i=1;i<=10;i++)
		__change(i,p%i,flt[c],p,1);
	s[p]=c;
}
inline int __query(int m,int rst,int c,register int r)
{
	if(!r)return 0;int sum=0;
	for(;r;r-=lowbit(r))sum+=tree[m][rst][c][r];
	return sum;
}
inline int ask(int m,int rst,int c,int l,int r)
{return __query(m,rst,c,r)-__query(m,rst,c,l-1);}
int main()
{
	flt['A']=0,flt['C']=1,flt['G']=2,flt['T']=3,scanf("%s",s+1);
	register int i,ii;
	l=strlen(s+1);int r;
	for(i=1;i<=l;i++)
		for(ii=1;ii<=10;ii++)
			__change(ii,i%ii,flt[s[i]],i,1);
	scanf("%d",&q);
	while(q--)
	{
		int o;
		scanf("%d",&o);
		if(o-1)
		{
			int lp,rp;
			scanf("%d%d%s",&lp,&rp,t+1);
			r=strlen(t+1);
			int ans=0;
			for(i=1;i<=r;i++)
			{
				int pos=(lp+i-1)%r,tp=flt[t[i]];
				ans+=ask(r,pos,tp,lp,rp);
			}printf("%d\n",ans);
		}
		else
		{
			int p,tp;
			char c=0;
			scanf("%d",&p);
			while(c<65||c>90)c=getchar();
			modify(p,c);
		}
	}
}