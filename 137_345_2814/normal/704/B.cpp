#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
#define N 5050
#define ll long long
int n,s,t,fg;
ll vl,v[N][5];
multiset<ll> tp;
int main()
{
	scanf("%d%d%d",&n,&s,&t);
	for(int i=0;i<5;i++)for(int j=1;j<=n;j++)scanf("%d",&v[j][i]);
	if(s>t){swap(s,t);for(int i=1;i<=n;i++)swap(v[i][1],v[i][3]),swap(v[i][2],v[i][4]);}
	for(int i=1;i<=n;i++)for(int j=1;j<=4;j++)v[i][j]+=v[i][0]*(j&1?1:-1);
	for(int i=1;i<=n;i++)
	if(i==s)
	{
		ll v0=v[i][3],v1=v[i][4];
		if(i==1)vl=v1;
		else vl+=v0,tp.insert(v1-v0);
		fg=1;
	}
	else if(i==t)
	{
		ll v0=v[i][1],v1=v[i][2];
		if(i==n)vl+=v0;
		else
		{
			vl+=v0;tp.insert(v1-v0);
			ll st=*tp.begin();vl+=st;tp.erase(tp.find(st));
		}
		fg=0;
	}
	else
	{
		if(i==1)vl+=v[i][2]+v[i][4];
		else if(i==n)vl+=v[i][1]+v[i][3];
		else
		{
			ll v0=v[i][1]+v[i][3],v1=min(v[i][1]+v[i][4],v[i][2]+v[i][3]),v2=v[i][2]+v[i][4];
			ll rvl=vl+v[i][1]+v[i][4];
			if(!tp.empty())rvl=min(rvl,vl+(*tp.begin())+v0);
			vl+=v0;tp.insert(v1-v0);tp.insert(v2-v1);
			ll st=*tp.begin();vl+=st;tp.erase(tp.find(st));
			if(fg)
			{
				if(!tp.empty())
				{
					ll st=*tp.begin();tp.erase(tp.find(st));
					tp.insert(st-rvl+vl);
				}
				vl=rvl;
			}
		}
	}
	printf("%lld\n",vl);
}