#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back
#define ls d<<1
#define rs d<<1|1

const int N=300005;

int n,cou[N],s1[N],s2[N],a[N],b[N],pos[N];
std::vector<int> vec[N];
struct tree{int s,mx,mn;}t[N*4];

void ins(int d,int l,int r,int x,int y)
{
	t[d].s++;
	t[d].mx=std::max(t[d].mx,y);
	t[d].mn=std::min(t[d].mn,y);
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y);
	else ins(rs,mid+1,r,x,y);
}

int query(int d,int l,int r,int x,int y)
{
	if (x>y) return 0;
	if (x<=l&&r<=y) return t[d].s;
	int mid=(l+r)/2;
	if (y<=mid) return query(ls,l,mid,x,y);
	else if (x>mid) return query(rs,mid+1,r,x,y);
	else return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
}

int get_mn(int d,int l,int r,int x,int y)
{
	if (x>y) return n+1;
	if (x<=l&&r<=y) return t[d].mn;
	int mid=(l+r)/2;
	if (y<=mid) return get_mn(ls,l,mid,x,y);
	else if (x>mid) return get_mn(rs,mid+1,r,x,y);
	else return std::min(get_mn(ls,l,mid,x,y),get_mn(rs,mid+1,r,x,y));
}

int get_mx(int d,int l,int r,int x,int y)
{
	if (x>y) return 0;
	if (x<=l&&r<=y) return t[d].mx;
	int mid=(l+r)/2;
	if (y<=mid) return get_mx(ls,l,mid,x,y);
	else if (x>mid) return get_mx(rs,mid+1,r,x,y);
	else return std::max(get_mx(ls,l,mid,x,y),get_mx(rs,mid+1,r,x,y));
}

void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) cou[i]=0,vec[i].clear();
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),cou[a[i]]++;
	for (int i=1;i<=n;i++) scanf("%d",&b[i]),cou[b[i]]--;
	for (int i=1;i<=n;i++) if (cou[i]) {puts("NO");return;}
	for (int i=1;i<=n;i++) vec[b[i]].pb(i);
	for (int i=n;i>=1;i--) pos[i]=vec[a[i]].back(),vec[a[i]].pop_back();
	for (int i=1;i<=n*4;i++) t[i].mn=n+1,t[i].mx=0,t[i].s=0;
	for (int i=1;i<=n;i++)
	{
		if (get_mn(1,1,n,pos[i]+1,n)<=a[i]) {puts("NO");return;}
		s1[i]=query(1,1,n,pos[i]+1,n);
		ins(1,1,n,pos[i],a[i]);
	}
	for (int i=1;i<=n*4;i++) t[i].mn=n+1,t[i].mx=0,t[i].s=0;
	for (int i=n;i>=1;i--)
	{
		if (get_mx(1,1,n,1,pos[i]-1)>=a[i]) {puts("NO");return;}
		s2[i]=query(1,1,n,1,pos[i]-1);
		ins(1,1,n,pos[i],a[i]);
	}
	for (int i=1;i<=n;i++)
		if (pos[i]<i&&i-pos[i]!=s1[i]-s2[i]||pos[i]>i&&pos[i]-i!=s2[i]-s1[i]) {puts("NO");return;}
	puts("YES");
}

int main()
{
	int T;scanf("%d",&T);
	while (T--) solve();
	return 0;
}