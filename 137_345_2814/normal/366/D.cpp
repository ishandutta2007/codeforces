#include<cstdio>
using namespace std;
struct edge{
	int t,next,l,r;
}ed[6147];
int head[1251],n,m,ans,ansl,ansr=-1,cnt,cl[1001],dl[1001];
inline int Max(int a,int b)
{
	return a>b?a:b;
}
void adde(int f,int t,int l,int r)
{
	ed[++cnt].t=t;
	ed[cnt].l=l;
	ed[cnt].r=r;
	ed[cnt].next=head[f];
	head[f]=cnt;
	ed[++cnt].t=f;
	ed[cnt].l=l;
	ed[cnt].r=r;
	ed[cnt].next=head[t];
	head[t]=cnt;
}
void dfs(int m,int fa,int l,int r)
{
	int ans1=r-l+1;
	if(ans1<ans||(ans1==ans&&l>=ansl))
	return;
	if(l>=cl[m]&&r<=dl[m])
	return;
	cl[m]=l;
	dl[m]=r;
	if(m==n)
	{
		ans=ans1;
		ansl=l;
		ansr=r;
		return;
	}
	for(int i=head[m];i;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		int nl=Max(ed[i].l,l),nr=-Max(-ed[i].r,-r);
		if(nl<=nr)
		dfs(ed[i].t,m,nl,nr);
	}
}
int main()
{
	int a,b,c,d;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	scanf("%d%d%d%d",&a,&b,&c,&d),adde(a,b,c,d);
	dfs(1,0,1,1010101);
	if(ans>0)
	printf("%d\n",ans);
	else
	printf("Nice work, Dima!");
	return 0;
}