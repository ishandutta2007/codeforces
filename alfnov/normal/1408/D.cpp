#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int a,b;
	bool operator<(const apple &other)const
	{
		return b>other.b;
	}
	apple(int a=0,int b=0):a(a),b(b){}
}p1[2005],p2[2005],as[4000005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d%d",&p1[i].a,&p1[i].b);
	for(int i=1;i<=m;i++)scanf("%d%d",&p2[i].a,&p2[i].b);
	int tot=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		if(p1[i].a>p2[j].a||p1[i].b>p2[j].b)continue;
		as[++tot]=apple(p2[j].a-p1[i].a+1,p2[j].b-p1[i].b+1);
	}
	sort(as+1,as+tot+1);
	int ans=INT_MAX,gs=0;
	for(int i=1;i<=tot+1;i++)
	{
		ans=min(ans,as[i].b+gs);
		gs=max(gs,as[i].a);
	}
	cout<<ans<<endl;
	return 0;
}