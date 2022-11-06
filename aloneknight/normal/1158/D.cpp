#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2005;
int n;char s[N];
struct P{int x,y,i;}p[N];
inline P operator+(const P&a,const P&b){return (P){a.x+b.x,a.y+b.y,0};}
inline P operator-(const P&a,const P&b){return (P){a.x-b.x,a.y-b.y,0};}
inline ll operator^(const P&a,const P&b){return 1ll*a.x*b.y-1ll*a.y*b.x;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y),p[i].i=i;
	scanf("%s",s+2);
	for(int i=2;i<=n;i++)if(p[i].x<p[1].x||(p[i].x==p[1].x&&p[i].y<p[1].y))swap(p[1],p[i]);
	for(int i=2;i<=n-1;i++)
	{
		P t=p[i-1];int k=i;
		if(s[i]=='L'){for(int j=i+1;j<=n;j++)if(((p[j]-t)^(p[k]-t))>0)k=j;}
		else if(s[i]=='R'){for(int j=i+1;j<=n;j++)if(((p[j]-t)^(p[k]-t))<0)k=j;}
		swap(p[i],p[k]);
	}
	for(int i=1;i<=n;i++)printf("%d ",p[i].i);
	return 0;
}