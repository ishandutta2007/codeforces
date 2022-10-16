#include<cstdio>
#include<algorithm>
#include<vector>
int n;
struct pii{int p,t;}P[1111111];
bool operator<(const pii x,const pii y)
{return(x.p!=y.p)?x.p<y.p:x.t>y.t;}
std::vector<pii>v[1111111];
void ins(int x,int y,int z)
{
	if(x<0)x=-x;if(y<0)y=-y;
	v[x].push_back(pii{y,z}),v[y].push_back(pii{x,z});
}
int col[1111111];
void dfs(int x,int c=1)
{col[x]=c;for(pii t:v[x])if(!col[t.p])dfs(t.p,c*t.t);}
int main()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)
	{
		int L,R;
		scanf("%d%d",&L,&R);
		P[i]=pii{L,i},P[i+n]=pii{R,-i};
	}
	std::sort(P+1,P+n*2+1);
	for(i=1;i<=n*2;i+=2)
	{
		if(P[i].t*1ll*P[i+1].t>0)ins(P[i].t,P[i+1].t,-1);
		else ins(P[i].t,P[i+1].t,1);
	}for(i=1;i<=n;i++)if(!col[i])dfs(i);
	for(i=1;i<=n;i++)printf("%d ",col[i]>0);puts("");
}
/*
Please don't let me down.
*/