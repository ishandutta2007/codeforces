#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,idt,a,b,c;
bool o;
int id[512];
LL v[102],ans[4];
struct aaa
{
	LL x;
	int o;
}A[512];
inline bool cmp(int x,int y)
{
	return A[x].x<A[y].x;
}
inline void newnode(int x,int y)
{
	A[++idt]=(aaa){x,y},id[idt]=idt;
}
inline void solve(int t)
{
	idt=a=b=c=0,newnode(1,0),newnode(((t+1)>>1),0),newnode(max(t-m,1),0);
	for(int i=1,x;i<=n;++i)x=(v[i]%t),newnode(1,1),newnode(min(x,t-x-1)+1,-1),newnode(max(t-x,(x/2)+1),2),newnode(1,3),newnode(x/2+1,-3);
	sort(id+1,id+idt+1,cmp);
	for(int i=1,j;i<idt;i=j)
	{
		for(j=i;j<=idt && A[id[j]].x==A[id[i]].x;++j)
			switch(A[id[j]].o)
			{
				case 1:++a;break;
				case 2:++b;break;
				case 3:++c;break;
				case -1:--a;break;
				case -2:--b;break;
				case -3:--c;break;
			}
		if(j>idt || A[id[j]].x>((t+1)>>1))break;
		if(A[id[j]].x<=max(t-m,1))continue;
		if(a || c>=2)ans[0]+=A[id[j]].x-A[id[i]].x;
		else if(c)
		{
			if(!((b+1)&1))ans[0]+=A[id[j]].x-A[id[i]].x;
			else ans[2]+=A[id[j]].x-A[id[i]].x;
		}
		else ans[3-(b&1)]+=A[id[j]].x-A[id[i]].x;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&v[i]);
	for(int i=2;i<=(m<<1);++i)solve(i);
	ans[1]+=ans[0],ans[2]<<=1,ans[3]<<=1;
	for(int i=1;i<=m;++i)
	{
		o=0;
		for(int j=1;j<=n;++j)o^=((v[j]/i)&1);
		++ans[3-o];
	}
	return 0&printf("%lld %lld %lld %lld",ans[0],ans[1],ans[2],ans[3]);
}