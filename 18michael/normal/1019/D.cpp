#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
int n,t=0;
LL s,tmp;
int id[2002],to[2002];
LL S1[2002],S2[2002];
struct aaa
{
	int x,y;
}p[2002];
struct bbb
{
	int a,b;
	LD k;
}b[4000002];
inline aaa mns(aaa a,aaa b)
{
	return (aaa){a.x-b.x,a.y-b.y};
}
inline LL cross(aaa a,aaa b)
{
	return (LL)a.x*b.y-(LL)a.y*b.x;
}
inline bool cmp(int x,int y)
{
	return S1[x]==S1[y]? (S2[x]>S2[y]):(S1[x]<S1[y]);
}
inline bool cmp1(bbb a,bbb b)
{
	return a.k<b.k;
}
inline void print(int x)
{
	printf("%d %d\n",p[x].x,p[x].y);
}
inline bool find(int a,int b)
{
	int l=1,r=n,mid;
	for(;l<=r;)
	{
		mid=((l+r)>>1);
		if((tmp=cross(mns(p[a],p[id[mid]]),mns(p[b],p[id[mid]])))==s)return puts("Yes"),print(id[mid]),print(a),print(b),1;
		if(tmp<s)l=mid+1;
		else r=mid-1;
	}
	return 0;
}
int main()
{
	scanf("%d%lld",&n,&s),s<<=1;
	for(int i=1;i<=n;++i)scanf("%d%d",&p[i].x,&p[i].y),id[i]=i;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i^j)b[++t]=(bbb){i,j,atan2(p[j].x-p[i].x,p[j].y-p[i].y)};
	sort(b+1,b+t+1,cmp1);
	for(int i=1;i<=n;++i)S1[i]=cross(mns(p[b[1].a],p[i]),mns(p[b[1].b],p[i])),S2[i]=cross(mns(p[b[2].a],p[i]),mns(p[b[2].b],p[i]));
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;++i)to[id[i]]=i;
	for(int i=1;i<=t;swap(to[b[i].a],to[b[i].b]),swap(id[to[b[i].a]],id[to[b[i].b]]),++i)if(find(b[i].a,b[i].b))return 0;
	return 0&puts("No");
}