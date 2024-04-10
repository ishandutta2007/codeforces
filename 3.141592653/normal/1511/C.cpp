#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
#include<vector>
using std::vector;
#include<cstdlib>
#include<queue>
using std::queue;
using std::priority_queue;
#include<cmath>
typedef long long ll;
typedef double db;
inline ll max(ll x,ll y)
{return(x<y)?y:x;}
inline ll min(ll x,ll y)
{return(x<y)?x:y;}
int n,q,t[1111111];
char s[1111111];
ll a[1111111];
int pos[1111111];
void exec()
{
	register int i,ii,iii;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(!pos[a[i]])pos[a[i]]=i;
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d",t+i);
		printf("%d ",pos[t[i]]);
		for(ii=1;ii<=50;ii++)if(pos[ii]<pos[t[i]])pos[ii]++;
		pos[t[i]]=1;
	}
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}