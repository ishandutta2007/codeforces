#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node
{
	ll k,b;
}q[400005],g;
int n,m,i,j,bg,ed;
ll s,b;
int main()
{
	scanf("%d%d",&n,&m);
	q[bg=ed=1]=(node){0,0};
	while(m--)
	{
		scanf("%d",&i);
		if(i==1)
		{
			scanf("%d",&i);
			s=b=0;
			q[bg=ed=1]=(node){0,0};
			n+=i;
		}
		else if(i==2)
		{
			scanf("%d",&i);
			g=(node){n,-(1ll*s*n+b)};
			while(ed>bg&&1.0*(q[ed].b-g.b)/(g.k-q[ed].k)>=1.0*(q[ed-1].b-q[ed].b)/(q[ed].k-q[ed-1].k))
				--ed;
			q[++ed]=g;
			n+=i;
		}
		else
		{
			scanf("%d%d",&i,&j);
			b+=i,s+=j;
		}
		while(bg<ed&&1.0*(q[ed].b-q[ed-1].b)/(q[ed-1].k-q[ed].k)<=s)
			--ed;
		printf("%lld %lld\n",q[ed].k+1,q[ed].k*s+q[ed].b+b);
	}
	return 0;
}