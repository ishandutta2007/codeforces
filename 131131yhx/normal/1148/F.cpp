#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=3e5+5;
int val[N];s64 mask[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n;
	rep(i,1,n)scanf("%d%lld",val+i,mask+i);
	s64 sum=0;
	rep(i,1,n)sum+=val[i];
	if(sum>0)rep(i,1,n)val[i]*=-1;
	s64 ans=0;
	rep(j,0,61)
	{
		sum=0;
		rep(i,1,n)
		if((mask[i]>>j)==1)sum+=val[i];
		if(sum<0)
		{
			ans|=1LL<<j;
			rep(i,1,n)
			if((mask[i]>>j)&1)val[i]*=-1;
		}
	}
	cout<<ans;
}