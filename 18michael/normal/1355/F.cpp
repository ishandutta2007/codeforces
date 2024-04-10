#include<cstdio>
#include<queue>
#include<vector>
#define Mx 100000
#define LL long long
#define inf 1000000000000000000LL
using namespace std;
int p_t=0,ans,res,Test_num;
LL Q;
int p[100002];
bool u[100002]={};
struct aaa
{
	int x,y;
	inline bool operator > (const aaa &a) const
	{
		return (y==a.y)? (x>a.x):(y<a.y);
	}
};
priority_queue<aaa,vector<aaa>,greater<aaa> > pq,ept;
vector<aaa> vec;
inline void init()
{
	for(int i=2;i<=Mx;++i)
	{
		if(!u[i])p[++p_t]=i;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
		}
	}
}
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c*=c;
	if(b&1)c*=a;
	return c;
}
inline void solve()
{
	ans=1,pq=ept;
	for(int i=1;i<=p_t;++i)pq.push((aaa){p[i],1});
	for(int i=1,x;i<=22;++i)
	{
		for(Q=1,vec.clear();Pow(pq.top().x,pq.top().y)<=inf/Q;pq.pop())Q*=Pow(pq.top().x,pq.top().y),vec.push_back(pq.top());
		printf("? %lld\n",Q),fflush(stdout),scanf("%d",&x);
		for(int j=0;j<vec.size();++j)
		{
			for(res=0;!(x%vec[j].x);++res)x/=vec[j].x;
			if(res>=vec[j].y)
			{
				ans/=vec[j].y,ans*=res+1;
				pq.push((aaa){vec[j].x,res+1});
			}
		}
	}
	printf("! %d\n",ans*2),fflush(stdout);
}
int main()
{
	init(),scanf("%d",&Test_num);
	while(Test_num--)solve();
	return 0;
}