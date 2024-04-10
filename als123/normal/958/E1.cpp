#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
LL n,m;
struct node{
	LL x,y;
}R[15],B[15];
struct line{
	node p1,p2;
}a[15];
LL multi(node p1,node p2,node p0)
{
    LL x1=p1.x-p0.x,x2=p2.x-p0.x;
    LL y1=p1.y-p0.y,y2=p2.y-p0.y;
    return x1*y2-x2*y1;
}
bool check(line l1,line l2)
{
    if(multi(l2.p1,l1.p2,l1.p1)*multi(l1.p2,l2.p2,l1.p1)>0&&multi(l1.p1,l2.p2,l2.p1)*multi(l2.p2,l1.p2,l2.p1)>0) return true;
    if(multi(l1.p1,l2.p1,l2.p2)==0&&min(l2.p1.x,l2.p2.x)<=l1.p1.x&&l1.p1.x<=max(l2.p1.x,l2.p2.x)) return true;
    if(multi(l1.p2,l2.p1,l2.p2)==0&&min(l2.p1.x,l2.p2.x)<=l1.p2.x&&l1.p2.x<=max(l2.p1.x,l2.p2.x)) return true;
    if(multi(l2.p1,l1.p1,l1.p2)==0&&min(l1.p1.x,l1.p2.x)<=l2.p1.x&&l2.p1.x<=max(l1.p1.x,l1.p2.x)) return true;
    if(multi(l2.p2,l1.p1,l1.p2)==0&&min(l1.p1.x,l1.p2.x)<=l2.p2.x&&l2.p2.x<=max(l1.p1.x,l1.p2.x)) return true;
    return false;
}
LL c[15];
bool solve(LL k)
{
	for(LL i=1;i<k;i++) if(check(a[i],a[k])) return false;
	return true;
}
void dfs(LL x)
{
	if(x>n) {printf("Yes");exit(0);}
	for(LL i=1;i<=m;i++)
	{
		if(c[i]) continue;
		a[x].p1=R[x];a[x].p2=B[i];
		if(!solve(x)) continue;
		c[i]=1;dfs(x+1);c[i]=0;
	}
}
int main()
{
	scanf("%lld %lld",&n,&m);
	if(n!=m) return puts("No"),0;
	for(LL i=1;i<=n;i++) scanf("%lld %lld",&R[i].x,&R[i].y);
	for(LL i=1;i<=m;i++) scanf("%lld %lld",&B[i].x,&B[i].y);
	memset(c,0,sizeof(c));
	dfs(1);
	printf("No\n");
}