#include<cstdio>
#define Mx 18
int n,n2,st_t=0,dep,ans;
int a[200002],l[200002],r[200002],fa[200002],st[200002],arr[800002]={},laz[800002]={};
int mn[400002][22];
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline int max(int x,int y)
{
	return x>y? x:y;
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void modify(int k,int l,int r,int l1,int r1,int d)
{
	if(l1>r1)return ;
	if(l>=l1 && r<=r1){laz[k]+=d;return ;}
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	laz[ls]+=laz[k],laz[rs]+=laz[k],laz[k]=0;
	if(r1<=mid)modify(ls,l,mid,l1,r1,d);
	else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
	else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
	arr[k]=max(arr[ls]+laz[ls],arr[rs]+laz[rs]);
}
inline int query(int k,int l,int r,int l1,int r1)
{
	if(l>=l1 && r<=r1)return arr[k]+laz[k];
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	laz[ls]+=laz[k],laz[rs]+=laz[k],arr[k]+=laz[k],laz[k]=0;
	if(r1<=mid)return query(ls,l,mid,l1,r1);
	if(l1>mid)return query(rs,mid+1,r,l1,r1);
	return max(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
}
inline int before_mn(int x)
{
	int t=mn[x][0];
	for(int i=Mx;~i;--i)if(x-(1<<i)>0 && mn[x-(1<<i)][i]>=t)x-=(1<<i);
	return x-1;
}
inline int after_mn(int x)
{
	int t=mn[x][0];++x;
	for(int i=Mx;~i;--i)if(x+(1<<i)<=n2 && mn[x][i]>=t)x+=(1<<i);
	if(mn[x][0]<=t)--x;
	return x+1<=n2? x+1:0;
}
int main()
{
	scanf("%d",&n),n2=(n<<1),st[0]=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]),mn[i][0]=mn[i+n][0]=a[i];
		while(a[i]<a[st[st_t]])--st_t;
		modify(1,1,n,i,i,st_t+1),modify(1,1,n,st[st_t]+1,i-1,1);
		l[i]=r[st[st_t]],fa[r[st[st_t]]]=i,r[st[st_t]]=i,fa[i]=st[st_t],st[++st_t]=i;
	}
	for(int i=1;i<=Mx;++i)
		for(int j=1;j<=n2;++j)
			mn[j][i]=min(mn[j][i-1],mn[min(n2,j+(1<<(i-1)))][i-1]);
	dep=arr[1]+laz[1],ans=0;
	for(int i=1,t;i<n;++i)
	{
		t=after_mn(i);
		if(t)
		{
			l[t%n]=r[i];
			if(r[i])fa[r[i]]=t%n;
		}
		else if(r[i])r[0]=r[i],fa[r[i]]=0;
		r[i]=0;
		modify(1,1,n,i,i,-query(1,1,n,i,i));
		if(!t)modify(1,1,n,1,i-1,-1),modify(1,1,n,i+1,n,-1);
		else if(t-1>n)modify(1,1,n,i+1,n,-1),modify(1,1,n,1,t-n-1,-1);
		else modify(1,1,n,i+1,t-1,-1);
		t=before_mn(i+n);
		l[i]=r[t? (t-1)%n+1:0];
		if(r[t? (t-1)%n+1:0])fa[r[t? (t-1)%n+1:0]]=i;
		r[t? (t-1)%n+1:0]=i,fa[i]=t? (t-1)%n+1:0;
		modify(1,1,n,i,i,t? query(1,1,n,(t-1)%n+1,(t-1)%n+1)+1:1);
		if(!t)modify(1,1,n,1,i-1,1),modify(1,1,n,i+1,n,1);
		else if(t+1<=n)modify(1,1,n,t+1,n,1),modify(1,1,n,1,i-1,1);
		else modify(1,1,n,t+1-n,i-1,1);
		if(arr[1]+laz[1]<dep)dep=arr[1]+laz[1],ans=i;
	}
	printf("%d %d",dep,ans);
	return 0;
}