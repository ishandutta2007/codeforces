#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
typedef pair<int,int> PI;
const int N=3005;
const int MAX=1e9+7;
priority_queue<PI> q1,q2,q3,q4;
int n,p,s; 
int a[N],b[N];
int bel[N];
int main()
{
	scanf("%d%d%d",&n,&p,&s);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	for (int u=1;u<=n;u++) scanf("%d",&b[u]);
	for (int u=1;u<=n;u++)
	{
		q1.push({a[u],u});
		q2.push({b[u],u});
	}
	q3.push({-MAX,n+1});bel[n+1]=1;
	q4.push({-MAX,n+2});bel[n+2]=2;
	int ans=0;
	//q1:A     q2:B     q3:A->B+A    q4:B->A+B
	while (p||s)
	{
		
		while (bel[q1.top().second]) q1.pop();
		while (bel[q2.top().second]) q2.pop();
		while (bel[q3.top().second]!=1) q3.pop();
		while (bel[q4.top().second]!=2) q4.pop();
		int mx=0,op=-1,x,y;
		if (p)
		{
			if (q1.top().first>mx)	{mx=q1.top().first;op=1;}
			if (q4.top().first+q2.top().first>mx)	{mx=q4.top().first+q2.top().first;op=2;}
		}
		if (s)
		{
			if (q2.top().first>mx)	{mx=q2.top().first;op=3;}
			if (q3.top().first+q1.top().first>mx)	{mx=q3.top().first+q1.top().first;op=4;}
		}
		//printf("%d %d\n",mx,op);
		ans=ans+mx;
		if (op==1)
		{
			p--;
			x=q1.top().second;q1.pop();
			bel[x]=1;q3.push({b[x]-a[x],x});
		}
		if (op==3)
		{
			s--;
			x=q2.top().second;q2.pop();
			bel[x]=2;q4.push({a[x]-b[x],x});
		}
		if (op==2)
		{
			p--;
			x=q2.top().second;q2.pop();
			y=q4.top().second;q4.pop();
			bel[x]=2;q4.push({a[x]-b[x],x});
			bel[y]=1;q3.push({b[y]-a[x],y});
		}
		if (op==4)
		{
			s--;
			x=q1.top().second;q1.pop();
			y=q3.top().second;q3.pop();
			bel[x]=1;q3.push({b[x]-a[x],x});
			bel[y]=2;q4.push({a[y]-b[y],y});
		}
	}
	printf("%d\n",ans);
	for (int u=1;u<=n;u++) if (bel[u]==1) printf("%d ",u);printf("\n");
	for (int u=1;u<=n;u++) if (bel[u]==2) printf("%d ",u);printf("\n");
	return 0;
}