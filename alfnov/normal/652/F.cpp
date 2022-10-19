#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int x,w,wz;
	bool operator<(const apple &other)const
	{
		return x<other.x;
	}
}e[300005];
int d[600005],ans[300005];
char s[155];
int main()
{
	int n,l;
	long long t,cs=0;
	cin>>n>>l>>t;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d%s",&x,s+1);
		int w=1;
		if(s[1]=='L')w=-1;
		x--;
		e[i].x=x,e[i].w=w,e[i].wz=i;
	}
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++)
	{
		int x=e[i].x,w=e[i].w;
		d[i]=(x+t*w%l+l)%l;
		if(w==1&&t>=l-x)cs+=1+(t-l+x)/l;
		if(w==-1&&t>=x+1)cs-=1+(t-x-1)/l;
		cs%=n;
	}
	cs=(cs%n+n)%n;
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i]++;
		d[i+n]=d[i];
	}
	for(int i=cs+1;i<=n+cs;i++)ans[e[i-cs].wz]=d[i];
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}