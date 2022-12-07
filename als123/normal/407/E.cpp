#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
const int MAX=1e9+7;
const int N=200005;
map<int,int> mp;
int n,k,d;
int a[N];
struct qq
{
	int l,r;
	int s1,s2;
	int c1,c2;//L+mx   L-mn
	int c;//mx-mn+L
	int lzy,lzy1;//mxmn 
}tr[N*2];int num;
void update (int now)
{
	int s1=tr[now].s1,s2=tr[now].s2;
	tr[now].c1=min(tr[s1].c1,tr[s2].c1);
	tr[now].c2=min(tr[s1].c2,tr[s2].c2);
	tr[now].c=min(tr[s1].c,tr[s2].c);
}
void bt (int l,int r)
{
	int now=++num;
	tr[now].l=l;tr[now].r=r;
	tr[now].lzy=tr[now].lzy1=MAX;
	if (l==r)	{tr[now].c=tr[now].c1=tr[now].c2=l;return ;}
	int mid=(l+r)>>1;
	tr[now].s1=num+1;bt(l,mid);
	tr[now].s2=num+1;bt(mid+1,r);
	update(now);
}
//int mx,mn;//   
//int c1,c2;//L+mx   L-mn
//int c;//mx-mn+L
void upd_max (int now,int c)
{
	tr[now].lzy=c;
	tr[now].c1=tr[now].l+c;
	tr[now].c=tr[now].c2+c;
}
void upd_min (int now,int c)
{
	tr[now].lzy1=c;
	tr[now].c2=tr[now].l-c;
	tr[now].c=tr[now].c1-c;
}
void Push_down (int now)
{
	int s1=tr[now].s1,s2=tr[now].s2;
	if (tr[now].lzy!=MAX)
	{
		upd_max(s1,tr[now].lzy);
		upd_max(s2,tr[now].lzy);
		tr[now].lzy=MAX;
	}
	if (tr[now].lzy1!=MAX)
	{
		upd_min(s1,tr[now].lzy1);
		upd_min(s2,tr[now].lzy1);
		tr[now].lzy1=MAX;
	}
}
void change (int now,int l,int r,int c,int op)//1:max   0:mn 
{
	/*if (tr[now].l==tr[now].r)
	{
		if (op==1)	{tr[now].mx=c;tr[now].c1=c+l;}
		else	{tr[now].mn=c;tr[now].c2=l-c;}
		tr[now].c=tr[now].mx-tr[now].mn+l;
		return ;
	}*/
	if (tr[now].l==l&&tr[now].r==r)
	{
		if (op==1) upd_max(now,c);
		else upd_min(now,c);
		return ;
	}
	Push_down(now);
	int mid=(tr[now].l+tr[now].r)>>1;
	int s1=tr[now].s1,s2=tr[now].s2;
	if (r<=mid) change(s1,l,r,c,op);
	else if (l>mid) change(s2,l,r,c,op);
	else change(s1,l,mid,c,op),change(s2,mid+1,r,c,op);
	update(now);
}
int ans,ans1;
void upd (int l,int r)
{
	if (ans<r-l+1)	{ans=r-l+1;ans1=l;}
}
int sta[N],top;
int sta1[N],top1;
int xx,R;
void solve (int now,int l,int r)
{
	if (xx!=-1) return ;	
	Push_down(now);
	//printf("%d %d %d %d %d\n",tr[now].l,tr[now].r,l,r,tr[now].c);
	if (tr[now].c-R>k) return ;
	if (tr[now].l==tr[now].r)	{xx=tr[now].l;return ;}
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (tr[now].l==l&&tr[now].r==r)
	{
	//	printf("lalal:%d %d\n",tr[s1].c,tr[s2].c);
		if (tr[s1].c-R<=k) solve(s1,l,mid);
		else solve(s2,mid+1,r);
		return ;
	}
	if (r<=mid) solve(s1,l,r);
	else if (l>mid)	solve(s2,l,r);
	else {solve(s1,l,mid);solve(s2,mid+1,r);}
}
int main()
{
//	freopen("3.in","r",stdin);
	
	scanf("%d%d%d",&n,&k,&d);
	for (int u=1;u<=n;u++)	scanf("%d",&a[u]);
	if (d==0)
	{
		int L=1;
		for (int u=1;u<=n;u++)
		{
			if (a[u]!=a[u-1]) L=u;
			upd(L,u);
		}
	}
	else
	{
		bt(1,n);
		int L=1;
		int ans=0,ans1;
		for (int u=1;u<=n;u++)// 
		{
//			if (abs(a[u])%d!=abs(a[u-1])%d)	L=u;
			if ((a[u]-a[u-1])%d!=0)	L=u;
			if (mp[a[u]]!=0) L=max(L,mp[a[u]]+1);
			mp[a[u]]=u;
			//[L,u]
			
		/*	int mx=a[u]/d,mn=a[u]/d;
			for (int i=u;i>=L;i--)
			{
				mx=max(mx,a[i]/d);
				mn=min(mn,a[i]/d);
				if (mx-mn+i-u<=k)	upd(i,u);
			}*/
			int now;
			while (top>0&&a[sta[top]]<a[u])	top--;
			now=sta[top]+1;sta[++top]=u;
			change(1,now,u,a[u]/d,1);
			
			while (top1>0&&a[sta1[top1]]>a[u]) top1--;
			now=sta1[top1]+1;sta1[++top1]=u;
			change(1,now,u,a[u]/d,0);
			
			xx=-1;R=u;
			solve(1,L,u);
			upd(xx,u);
		//	if (u==99996) printf("YES:%d\n",L);
		//	printf("YES:%d %d %d\n",L,xx,u);
		}
	}
	printf("%d %d\n",ans1,ans1+ans-1);
	return 0;
}