#include<bits/stdc++.h>
using namespace std;
int mx,my,mz,n,m,k,x,y,z,i,ans[100005],num[4],t,l;
int lx=1<<30,rx,ly=1<<30,ry,lz=1<<30,rz;
int tree[400005];
struct kimisame{
	int x,y,z;
}p[100005],tmp[100005];
struct margatroid{
	int x,y,z,id;
}q[4][100005];
bool kcmp1(kimisame a,kimisame b)
{
	return a.x>b.x;
}
bool kcmp2(kimisame a,kimisame b)
{
	return a.x<b.x;
}
bool mcmp1(margatroid a,margatroid b)
{
	return a.x>b.x;
}
bool mcmp2(margatroid a,margatroid b)
{
	return a.x<b.x;
}
int Query1(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return tree[i];
	int mid=l+r>>1,ans=1<<30;
	if(mid>=ll)
		ans=min(ans,Query1(i<<1,l,mid,ll,rr));
	if(mid<rr)
		ans=min(ans,Query1(i<<1|1,mid+1,r,ll,rr));
	return ans;
}
void modify1(int i,int l,int r,int x,int y)
{
	if(l==r)
	{
		tree[i]=min(tree[i],y);
		return;
	}
	int mid=l+r>>1;
	if(mid>=x)
		modify1(i<<1,l,mid,x,y);
	else
		modify1(i<<1|1,mid+1,r,x,y);
	tree[i]=min(tree[i<<1],tree[i<<1|1]);
}
int Query2(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return tree[i];
	int mid=l+r>>1,ans=0;
	if(mid>=ll)
		ans=max(ans,Query2(i<<1,l,mid,ll,rr));
	if(mid<rr)
		ans=max(ans,Query2(i<<1|1,mid+1,r,ll,rr));
	return ans;
}
void modify2(int i,int l,int r,int x,int y)
{
	if(l==r)
	{
		tree[i]=max(tree[i],y);
		return;
	}
	int mid=l+r>>1;
	if(mid>=x)
		modify2(i<<1,l,mid,x,y);
	else
		modify2(i<<1|1,mid+1,r,x,y);
	tree[i]=max(tree[i<<1],tree[i<<1|1]);
}
int main()
{
	scanf("%d %d %d %d %d %d",&mx,&my,&mz,&n,&m,&k);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d %d",&x,&y,&z);
		lx=min(lx,x),ly=min(ly,y),lz=min(lz,z);
		rx=max(rx,x),ry=max(ry,y),rz=max(rz,z);
	}
	for(i=1;i<=m;++i)
	{
		scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);
		if(p[i].x>=lx&&p[i].x<=rx&&p[i].y>=ly&&p[i].y<=ry&&p[i].z>=lz&&p[i].z<=rz)
		{
			puts("INCORRECT");
			return 0;
		}
	}
	puts("CORRECT");
	for(i=1;i<=k;++i)
	{
		int g=0;
		scanf("%d %d %d",&x,&y,&z);
		if(x>=lx&&x<=rx&&y>=ly&&y<=ry&&z>=lz&&z<=rz)
		{
			ans[i]=-1;
			continue;
		}
		if(x>rx)
			g+=2;
		if(z>rz)
			++g;
		q[g][++num[g]]=(margatroid){x,y,z,i};
	}
	for(i=0;i<2;++i)
		sort(q[i]+1,q[i]+1+num[i],mcmp1);
	for(i=2;i<4;++i)
		sort(q[i]+1,q[i]+1+num[i],mcmp2);
	t=0;
	for(i=1;i<=m;++i)
		if(p[i].x<=rx&&p[i].z<=rz)
			tmp[++t]=p[i];
	sort(tmp+1,tmp+1+t,kcmp1);
	memset(tree,0,sizeof(tree));
	l=1;
	for(i=1;i<=num[0];++i)
	{
		while(l<=t&&tmp[l].x>=min(lx,q[0][i].x))
		{
			modify2(1,1,my,tmp[l].y,tmp[l].z);
			++l;
		}
		ans[q[0][i].id]=(Query2(1,1,my,min(ly,q[0][i].y),max(ry,q[0][i].y))<min(q[0][i].z,lz));
	}
	t=0;
	for(i=1;i<=m;++i)
		if(p[i].x<=rx&&p[i].z>=lz)
			tmp[++t]=p[i];
	sort(tmp+1,tmp+1+t,kcmp1);
	memset(tree,0x7f,sizeof(tree));
	l=1;
	for(i=1;i<=num[1];++i)
	{
		while(l<=t&&tmp[l].x>=min(lx,q[1][i].x))
		{	
			modify1(1,1,my,tmp[l].y,tmp[l].z);
			++l;
		}
		ans[q[1][i].id]=(Query1(1,1,my,min(ly,q[1][i].y),max(ry,q[1][i].y))>q[1][i].z);
	}
	t=0;
	for(i=1;i<=m;++i)
		if(p[i].x>=lx&&p[i].z<=rz)
			tmp[++t]=p[i];
	sort(tmp+1,tmp+1+t,kcmp2);
	memset(tree,0,sizeof(tree));
	l=1;
	for(i=1;i<=num[2];++i)
	{
		while(l<=t&&tmp[l].x<=q[2][i].x)
		{
			modify2(1,1,my,tmp[l].y,tmp[l].z);
			++l;
		}
		ans[q[2][i].id]=(Query2(1,1,my,min(ly,q[2][i].y),max(ry,q[2][i].y))<min(q[2][i].z,lz));
	}
	t=0;
	for(i=1;i<=m;++i)
		if(p[i].x>=lx&&p[i].z>=lz)
			tmp[++t]=p[i];
	sort(tmp+1,tmp+1+t,kcmp2);
	memset(tree,0x7f,sizeof(tree));
	l=1;
	for(i=1;i<=num[3];++i)
	{
		while(l<=t&&tmp[l].x<=q[3][i].x)
		{
			modify1(1,1,my,tmp[l].y,tmp[l].z);
			++l;
		}
		ans[q[3][i].id]=(Query1(1,1,my,min(ly,q[3][i].y),max(ry,q[3][i].y))>q[3][i].z);
	}
	for(i=1;i<=k;++i)
		if(ans[i]==-1)
			puts("OPEN");
		else
			puts(ans[i]?"UNKNOWN":"CLOSED");
}