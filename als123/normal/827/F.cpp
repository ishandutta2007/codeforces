#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N=1e6+5;
int n,m;
int od[N],ev[N],nn;
struct qq
{
	int x,y,l,r;
};
bool operator < (qq x,qq y)	{return x.l>y.l;}
priority_queue<qq> q;
void init (int x,int y,int l,int r)
{
	//printf("%d %d\n",l,r);
	if (l>r) return ;
	qq now;
	now.x=x;now.y=y;now.l=l;now.r=r;
	q.push(now);
}
int last[N];
vector<qq> vec[N];
int id[N];
void upd (int now,int t)
{
	int siz=vec[now].size()-1;
	while (id[now]<=siz&&vec[now][id[now]].l<=last[now])
	{
		vec[now][id[now]].l=max(vec[now][id[now]].l,t);
		if (vec[now][id[now]].l<=vec[now][id[now]].r) q.push(vec[now][id[now]]);
		id[now]++;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	if (n==1)	{printf("0\n");return 0;}
	for (int u=1;u<=n;u++) od[u]=++nn,ev[u]=++nn;
	for (int u=1;u<=m;u++)
	{
		int x,y,l,r;
		scanf("%d%d%d%d",&x,&y,&l,&r);r--;
		init(od[x],ev[y],(l&1)?l:l+1,(r&1)?r:r-1);
		init(od[y],ev[x],(l&1)?l:l+1,(r&1)?r:r-1);
		init(ev[x],od[y],(l&1)?l+1:l,(r&1)?r-1:r);
		init(ev[y],od[x],(l&1)?l+1:l,(r&1)?r-1:r);
	}
	memset(last,-127,sizeof(last));
	last[ev[1]]=0;
	while (!q.empty())
	{
		qq now=q.top();q.pop();
		//printf("%d %d %d\n",now.x,now.y,last[now.x]);
		if (last[now.x]>=now.l)
		{
			if (now.y==ev[n]||now.y==od[n])	{printf("%d\n",now.l+1);return 0;}
			last[now.x]=max(last[now.x],now.r);
			last[now.y]=max(last[now.y],now.r+1);
			upd(now.y,now.l+1);
		}
		else	vec[now.x].push_back(now);
	}
	printf("-1\n");
	return 0;
}