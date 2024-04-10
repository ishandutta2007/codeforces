#include<cstdio>
#include<algorithm>
#define LL long long
#define Mx 1000001
using namespace std;
int n,m,p_t=0,q_t=0,pt=1,qt=1,t;
LL ans=1;
LL arr[1000002]={};
struct aaa
{
	int tim,pos,opt;
}p[200002];
struct bbb
{
	int tim,st,ed;
}q[100002];
inline bool cmp(aaa a,aaa b)
{
	return a.tim==b.tim? (a.opt>b.opt):(a.tim<b.tim);
}
inline bool cmp1(bbb a,bbb b)
{
	return a.tim<b.tim? 1:0;
}
inline int min(int a,int b)
{
	return a<b? a:b;
}
inline int lowbit(int x)
{
	return x&(-x);
}
inline void modify(int x,int d)
{
	while(x<=Mx)arr[x]+=d,x+=lowbit(x);
}
inline LL query(int x)
{
	LL res=0;
	while(x)res+=arr[x],x-=lowbit(x);
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=n;++i)
	{
		scanf("%d%d%d",&x,&y,&z),++x,++y,++z,p[++p_t]=(aaa){y,x,1},p[++p_t]=(aaa){z,x,-1};
		if(y==1 && z==Mx)++ans;
	}
	for(int i=1,x,y,z;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&z),++x,++y,++z,q[++q_t]=(bbb){x,y,z};
		if(y==1 && z==Mx)++ans;
	}
	sort(p+1,p+p_t+1,cmp),sort(q+1,q+q_t+1,cmp1);
	while(pt<=p_t && qt<=q_t)
	{
		t=min(p[pt].tim,q[qt].tim);
		
		while(pt<=p_t && p[pt].tim==t && p[pt].opt==1)modify(p[pt].pos,p[pt].opt),++pt;
		while(qt<=q_t && q[qt].tim==t)ans+=query(q[qt].ed)-query(q[qt].st-1),++qt;
		while(pt<=p_t && p[pt].tim==t)modify(p[pt].pos,p[pt].opt),++pt;
	}
	while(qt<=q_t)ans+=query(q[qt].ed)-query(q[qt].st-1),++qt;
	printf("%lld",ans);
	return 0;
}