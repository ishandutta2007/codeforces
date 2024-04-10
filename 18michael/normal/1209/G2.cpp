#include<bits/stdc++.h>
#define Mx 200000
using namespace std;
int n,q;
int a[200002];
set<int> s[200002];
struct aaa
{
	int laz,mnb,mxd,num,lmx,rmx;
}arr[800002];
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void pushdown(int k)
{
	int ls=lson(k),rs=rson(k);
	arr[ls].mnb+=arr[k].laz,arr[rs].mnb+=arr[k].laz,arr[ls].laz+=arr[k].laz,arr[rs].laz+=arr[k].laz,arr[k].laz=0;
}
inline void pushup(int k)
{
	int ls=lson(k),rs=rson(k);
	arr[k].mnb=min(arr[ls].mnb,arr[rs].mnb),arr[k].mxd=max(arr[ls].mxd,arr[rs].mxd);
	if(arr[ls].mnb<arr[rs].mnb)arr[k].num=arr[ls].num,arr[k].lmx=arr[ls].lmx,arr[k].rmx=max(arr[ls].rmx,arr[rs].mxd);
	else if(arr[ls].mnb>arr[rs].mnb)arr[k].num=arr[rs].num,arr[k].lmx=max(arr[ls].mxd,arr[rs].lmx),arr[k].rmx=arr[rs].rmx;
	else arr[k].num=arr[ls].num+arr[rs].num+max(arr[ls].rmx,arr[rs].lmx),arr[k].lmx=arr[ls].lmx,arr[k].rmx=arr[rs].rmx;
}
inline void modifyB(int k,int l,int r,int l1,int r1,int d)
{
	if(l1>r1)return ;
	if(l>=l1 && r<=r1){arr[k].mnb+=d,arr[k].laz+=d;return ;}
	int mid=((l+r)>>1);pushdown(k);
	if(r1<=mid)modifyB(lson(k),l,mid,l1,r1,d);
	else if(l1>mid)modifyB(rson(k),mid+1,r,l1,r1,d);
	else modifyB(lson(k),l,mid,l1,mid,d),modifyB(rson(k),mid+1,r,mid+1,r1,d);
	pushup(k);
}
inline void modifyD(int k,int l,int r,int x,int d)
{
	if(l==r){arr[k].mxd=arr[k].lmx=d;return ;}
	int mid=((l+r)>>1);pushdown(k);
	if(x<=mid)modifyD(lson(k),l,mid,x,d);
	else modifyD(rson(k),mid+1,r,x,d);
	pushup(k);
}
inline void ins(int x)
{
	if(!s[a[x]].empty())modifyB(1,1,n,*s[a[x]].begin(),*s[a[x]].rbegin()-1,-1),modifyD(1,1,n,*s[a[x]].begin(),0);
	s[a[x]].insert(x),modifyD(1,1,n,*s[a[x]].begin(),s[a[x]].size()),modifyB(1,1,n,*s[a[x]].begin(),*s[a[x]].rbegin()-1,1);
}
inline void del(int x)
{
	modifyB(1,1,n,*s[a[x]].begin(),*s[a[x]].rbegin()-1,-1),modifyD(1,1,n,*s[a[x]].begin(),0),s[a[x]].erase(x);
	if(!s[a[x]].empty())modifyD(1,1,n,*s[a[x]].begin(),s[a[x]].size()),modifyB(1,1,n,*s[a[x]].begin(),*s[a[x]].rbegin()-1,1);
}
inline void query()
{
	printf("%d\n",n-arr[1].num-arr[1].lmx-arr[1].rmx);
}
int main()
{
	scanf("%d%d",&n,&q);for(int i=1;i<=n;++i)scanf("%d",&a[i]),ins(i);query();
	for(int x,y,z;q--;)scanf("%d%d",&x,&y),z=a[x],del(x),a[x]=y,ins(x),query();
	return 0;
}