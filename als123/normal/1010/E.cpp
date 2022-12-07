#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1000005;
int X,Y,Z,n,m,k;
struct qq
{
	int son[2];
	int d[3];
	int mx[3],mn[3];
}tr[N];
int cmpd;
bool cmp (qq x,qq y)
{
	return x.d[cmpd]<y.d[cmpd]||(x.d[cmpd]==y.d[cmpd]&&x.d[(cmpd+1)%3]<y.d[(cmpd+1)%3])||(x.d[cmpd]==y.d[cmpd]&&x.d[(cmpd+1)%3]==y.d[(cmpd+1)%3]&&x.d[(cmpd+2)%3]<y.d[(cmpd+2)%3]);
}
void update (int x,int y)
{
	for (int u=0;u<3;u++)
	{
		tr[x].mn[u]=min(tr[x].mn[u],tr[y].mn[u]);
		tr[x].mx[u]=max(tr[x].mx[u],tr[y].mx[u]);
	}
}
int bt (int l,int r,int d)
{
	cmpd=d;int mid=(l+r)>>1;
	nth_element(tr+l,tr+mid,tr+r+1,cmp);
	for (int u=0;u<3;u++) tr[mid].mx[u]=tr[mid].mn[u]=tr[mid].d[u];
	if (l<mid) tr[mid].son[0]=bt(l,mid-1,(d+1)%3),update(mid,tr[mid].son[0]);
	if (mid<r) tr[mid].son[1]=bt(mid+1,r,(d+1)%3),update(mid,tr[mid].son[1]);
	return mid;
}
int Mn1,Mn2,Mn3,Mx1,Mx2,Mx3;
bool check (int now)
{
	if (tr[now].mx[0]<Mn1||tr[now].mn[0]>Mx1) return false;
	if (tr[now].mx[1]<Mn2||tr[now].mn[1]>Mx2) return false;
	if (tr[now].mx[2]<Mn3||tr[now].mn[2]>Mx3) return false;
	return true;
}
bool check1 (int now)
{
	bool tf=true;
	tf=tf&(tr[now].mn[0]>=Mn1&tr[now].mx[0]<=Mx1);
	tf=tf&(tr[now].mn[1]>=Mn2&&tr[now].mx[1]<=Mx2);
	tf=tf&(tr[now].mn[2]>=Mn3&tr[now].mx[2]<=Mx3);
	return tf;
}
bool find (int now)
{

	if (now==0) return false;//printf("%d %d %d %d %d %d %d\n",now,tr[now].mn[0],tr[now].mx[0],tr[now].mn[1],tr[now].mx[1],tr[now].mn[2],tr[now].mx[2]);
	if (!check(now)) return false;
	if (check1(now)) return true;
	if (tr[now].d[0]>=Mn1&&tr[now].d[0]<=Mx1&&tr[now].d[1]>=Mn2&&tr[now].d[1]<=Mx2&&tr[now].d[2]>=Mn3&&tr[now].d[2]<=Mx3) 	return true;
	if (find(tr[now].son[0])) return true;
	if (find(tr[now].son[1])) return true;
	return false;
}
int main()
{
	scanf("%d%d%d%d%d%d",&X,&Y,&Z,&n,&m,&k);
	int mn1=X,mn2=Y,mn3=Z,mx1=1,mx2=1,mx3=1;
	for (int u=1;u<=n;u++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		mn1=min(mn1,x);mn2=min(mn2,y);mn3=min(mn3,z);
		mx1=max(mx1,x);mx2=max(mx2,y);mx3=max(mx3,z);
	}
	for (int u=1;u<=m;u++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (x>=mn1&&x<=mx1&&y>=mn2&&y<=mx2&&z>=mn3&&z<=mx3) 	{printf("INCORRECT\n");return 0;}
		tr[u].d[0]=x;tr[u].d[1]=y;tr[u].d[2]=z;
	}
	printf("CORRECT\n");
	int rt=bt(1,m,0);
	for (int u=1;u<=k;u++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (x>=mn1&&x<=mx1&&y>=mn2&&y<=mx2&&z>=mn3&&z<=mx3) 	printf("OPEN\n");
		else
		{
			Mn1=min(mn1,x);Mn2=min(mn2,y);Mn3=min(mn3,z);
			Mx1=max(mx1,x);Mx2=max(mx2,y);Mx3=max(mx3,z);
		//	printf("%d %d %d %d %d %d\n",Mn1,Mn2,Mn3,Mx1,Mx2,Mx3);
			if (find(rt)) printf("CLOSED\n");
			else printf("UNKNOWN\n");
		}
	}
	return 0;
}