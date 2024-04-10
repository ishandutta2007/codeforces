#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=100005;

int n,m,q,X,Y,Z,D,tot,Mx1,Mx2,Mx3,Mn1,Mn2,Mn3;
struct data{int d[3],mn[3],mx[3],l,r,s;}t[N];

bool cmp(data a,data b)
{
    return a.d[D]<b.d[D]||a.d[D]==b.d[D]&&a.d[(D+1)%3]<b.d[(D+1)%3]||a.d[D]==b.d[D]&&a.d[(D+1)%3]==b.d[(D+1)%3]&&a.d[(D+2)%3]<b.d[(D+2)%3];
}

void updata(int x,int y)
{
    t[x].mn[0]=std::min(t[x].mn[0],t[y].mn[0]);
    t[x].mn[1]=std::min(t[x].mn[1],t[y].mn[1]);
    t[x].mn[2]=std::min(t[x].mn[2],t[y].mn[2]);
    t[x].mx[0]=std::max(t[x].mx[0],t[y].mx[0]);
    t[x].mx[1]=std::max(t[x].mx[1],t[y].mx[1]);
    t[x].mx[2]=std::max(t[x].mx[2],t[y].mx[2]);
}

int build(int l,int r,int dd)
{
    D=dd;int mid=(l+r)/2;
    std::nth_element(t+l,t+mid,t+r+1,cmp);
    t[mid].mn[0]=t[mid].mx[0]=t[mid].d[0];
    t[mid].mn[1]=t[mid].mx[1]=t[mid].d[1];
    t[mid].mn[2]=t[mid].mx[2]=t[mid].d[2];
    if (l<mid) t[mid].l=build(l,mid-1,(dd+1)%3),updata(mid,t[mid].l);
    if (r>mid) t[mid].r=build(mid+1,r,(dd+1)%3),updata(mid,t[mid].r);
    t[mid].s=t[t[mid].l].s+t[t[mid].r].s+1;
    return mid;
}

bool inc(int l1,int r1,int l2,int r2)
{
	if (l1>r2||l2>r1) return 0;
	else return 1;
}

bool inc(int d)
{
	if (!inc(t[d].mn[0],t[d].mx[0],Mn1,Mx1)) return 0;
	if (!inc(t[d].mn[1],t[d].mx[1],Mn2,Mx2)) return 0;
	if (!inc(t[d].mn[2],t[d].mx[2],Mn3,Mx3)) return 0;
	return 1;
}

bool check(int l1,int r1,int l2,int r2)
{
	return l2<=l1&&r2>=r1;
}

bool check(int d)
{
	if (!check(t[d].mn[0],t[d].mx[0],Mn1,Mx1)) return 0;
	if (!check(t[d].mn[1],t[d].mx[1],Mn2,Mx2)) return 0;
	if (!check(t[d].mn[2],t[d].mx[2],Mn3,Mx3)) return 0;
	return 1;
}

bool query(int d)
{
	if (!d) return 0;
	if (!inc(d)) return 0;
	if (check(d)) return 1;
	if (t[d].d[0]>=Mn1&&t[d].d[0]<=Mx1&&t[d].d[1]>=Mn2&&t[d].d[1]<=Mx2&&t[d].d[2]>=Mn3&&t[d].d[2]<=Mx3) return 1;
	if (query(t[d].l)) return 1;
	if (query(t[d].r)) return 1;
	return 0;
}

int main()
{
	scanf("%d%d%d%d%d%d",&X,&Y,&Z,&n,&m,&q);
	int mx1=1,mn1=X,mx2=1,mx3=1,mn2=Y,mn3=Z;
	for (int i=1;i<=n;i++)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		mx1=std::max(mx1,x);mn1=std::min(mn1,x);
		mx2=std::max(mx2,y);mn2=std::min(mn2,y);
		mx3=std::max(mx3,z);mn3=std::min(mn3,z);
	}
	for (int i=1;i<=m;i++)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		if (x>=mn1&&x<=mx1&&y>=mn2&&y<=mx2&&z>=mn3&&z<=mx3) {puts("INCORRECT");return 0;}
		tot++;t[tot].d[0]=x;t[tot].d[1]=y;t[tot].d[2]=z;
	}
	puts("CORRECT");
	int rt=build(1,tot,0);
	for (int i=1;i<=q;i++)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		if (x>=mn1&&x<=mx1&&y>=mn2&&y<=mx2&&z>=mn3&&z<=mx3) puts("OPEN");
		else
		{
			Mx1=mx1;Mn1=mn1;Mx2=mx2;Mn2=mn2;Mx3=mx3;Mn3=mn3;
			Mx1=std::max(Mx1,x);Mn1=std::min(Mn1,x);
			Mx2=std::max(Mx2,y);Mn2=std::min(Mn2,y);
			Mx3=std::max(Mx3,z);Mn3=std::min(Mn3,z);
			if (query(rt)) puts("CLOSED");
			else puts("UNKNOWN");
		}
	}
	return 0;
}