#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100500
#define M 12345678
int n,v[N],d[N],s1[N],s2[N],ct1,ct2,as=2e9,ls[N];
struct sth{int l,r,x;};
vector<sth> st1[N],st2[N];
int ct=1,ch[M][2],lz[M],mn[M];
void pushup(int x){mn[x]=min(mn[ch[x][0]],mn[ch[x][1]])+lz[x];}
void modify(int x,int l,int r,int l1,int r1,int v)
{
	if(l==l1&&r==r1){lz[x]+=v,mn[x]+=v;return;}
	int mid=(l+r)>>1;
	if(mid<r1&&!ch[x][1])ch[x][1]=++ct;
	if(mid>=l1&&!ch[x][0])ch[x][0]=++ct;
	if(mid>=r1)modify(ch[x][0],l,mid,l1,r1,v);
	else if(mid<l1)modify(ch[x][1],mid+1,r,l1,r1,v);
	else modify(ch[x][0],l,mid,l1,mid,v),modify(ch[x][1],mid+1,r,mid+1,r1,v);
	pushup(x);
}
int query(int x,int l,int r,int l1,int r1)
{
	if(l>r)return 2e9;
	if(!x||(l==l1&&r==r1))return mn[x];
	int mid=(l+r)>>1;
	if(mid>=r1)return query(ch[x][0],l,mid,l1,r1)+lz[x];
	else if(mid<l1)return query(ch[x][1],mid+1,r,l1,r1)+lz[x];
	else return min(query(ch[x][0],l,mid,l1,mid),query(ch[x][1],mid+1,r,mid+1,r1))+lz[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++)scanf("%d",&v[i]);
	d[0]=d[n+1]=1e9;
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	lz[1]=mn[1]=v[n+1];
	s1[ct1=1]=0;
	for(int i=1;i<=n+1;i++)
	{
		while(ct1>1&&d[s1[ct1]]*2+v[s1[ct1-1]]<v[i])ct1--;
		ls[i]=s1[ct1];s1[++ct1]=i;
	}
	if(ct1>2){printf("0\n");return 0;}
	ct1=1;
	for(int i=1;i<=n;i++)
	{
		while(ct1>1&&d[s1[ct1]]*2+v[ls[s1[ct1]]]<=d[i]*2+v[ls[i]])st1[i].push_back((sth){0,d[s1[ct1]]*2+v[ls[s1[ct1]]],v[s1[ct1]]-v[s1[ct1-1]]}),ct1--;
		s1[++ct1]=i;st1[i].push_back((sth){0,d[s1[ct1]]*2+v[ls[s1[ct1]]],-v[s1[ct1]]+v[s1[ct1-1]]});
	}
	ct1=1;s1[1]=n+1;
	for(int i=n;i>=0;i--)
	{
		while(ct1>1&&-d[s1[ct1]]*2+v[s1[ct1-1]]>v[i])ct1--;
		ls[i]=s1[ct1];s1[++ct1]=i;
	}
	ct1=1;
	for(int i=n;i>=1;i--)
	{
		while(ct1>1&&-d[s1[ct1]]*2+v[ls[s1[ct1]]]>=-d[i]*2+v[ls[i]])modify(1,0,v[n+1],-d[s1[ct1]]*2+v[ls[s1[ct1]]],v[n+1],-v[s1[ct1]]+v[s1[ct1-1]]),st2[i].push_back((sth){-d[s1[ct1]]*2+v[ls[s1[ct1]]],v[n+1],v[s1[ct1]]-v[s1[ct1-1]]}),ct1--;
		s1[++ct1]=i;modify(1,0,v[n+1],-d[s1[ct1]]*2+v[ls[s1[ct1]]],v[n+1],v[s1[ct1]]-v[s1[ct1-1]]);st2[i].push_back((sth){-d[s1[ct1]]*2+v[ls[s1[ct1]]],v[n+1],-v[s1[ct1]]+v[s1[ct1-1]]});
	}
	for(int i=1;i<=n+1;i++)
	{
		for(int j=0;j<st2[i-1].size();j++)
		modify(1,0,v[n+1],st2[i-1][j].l,st2[i-1][j].r,st2[i-1][j].x);
		as=min(as,query(1,0,v[n+1],v[i-1],v[i-1]));
		for(int j=0;j<st1[i-1].size();j++)
		modify(1,0,v[n+1],st1[i-1][j].l,st1[i-1][j].r,st1[i-1][j].x);
		as=min(as,query(1,0,v[n+1],v[i-1]+1,v[i]-1));
	}
	printf("%.1lf\n",as/2.0);
}