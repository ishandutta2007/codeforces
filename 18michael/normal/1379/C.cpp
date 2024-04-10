#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
int n,m,Test_num;LL ans;
int Pa[100002],Pb[100002];
bool u[200002];
struct aaa
{
	int val,num;
}p[200002];
inline bool cmp(aaa a,aaa b)
{
	return a.val>b.val? 1:0;
}
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
inline void calc(int x,int y,LL z)
{
	if(!y){ans=max(ans,z);return ;}
	if(x>=2*m)return ;
	if(!(p[x].num&1))
	{
		u[p[x].num]=1;
		if(!u[p[x].num^1])calc(x+1,y-1,z+p[x].val);
		else ans=max(ans,z+p[x].val+1LL*(y-1)*Pb[p[x].num/2]);
	}
	else if(u[p[x].num^1])ans=max(ans,z+1LL*y*p[x].val);
	else ans=max(ans,z+Pa[p[x].num/2]+1LL*(y-1)*p[x].val),calc(x+1,y,z);
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		ans=0,scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i)scanf("%d%d",&p[2*i].val,&p[2*i+1].val),p[2*i].num=2*i,p[2*i+1].num=2*i+1,Pa[i]=p[2*i].val,Pb[i]=p[2*i+1].val,u[2*i]=u[2*i+1]=0;
		sort(p,p+2*m,cmp),calc(0,n,0),printf("%lld\n",ans);
	}
	return 0;
}