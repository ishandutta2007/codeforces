#include<cstdio>
#include<cstring>
const int maxn=200001;
int n,a[maxn],q[maxn<<2],d[maxn];
bool v[maxn];
inline void bfs()
{
	memset(v,false,sizeof(v));
	int h=0,t=1;
	q[1]=1;
	v[1]=true;
	d[1]=0;
	while(h<t)
	{
		int x=q[++h];
		if(x<n&&v[x+1]==false)
		{
			d[x+1]=d[x]+1;
			q[++t]=x+1;
			v[x+1]=true;
		}
		if(!v[a[x]])
		{
			d[a[x]]=d[x]+1;
			q[++t]=a[x];
			v[a[x]]=true;
		}
		if(x>1&&v[x-1]==false)
		{
			d[x-1]=d[x]+1;
			q[++t]=x-1;
			v[x-1]=true;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	bfs();
	for(int i=1;i<=n;i++)printf("%d ",d[i]);
	return 0;
}