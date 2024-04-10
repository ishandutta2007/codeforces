#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define LL long long
using namespace std;
int n,t=0,t1=0;
LL x,ans=0;
int cnt[1000002];
LL a[1000002];
vector<LL> vec;
inline int RND()
{
	int res=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	return ((res%n)+n)%n+1;
}
inline LL gcd(LL x,LL y)
{
	return y? gcd(y,x%y):x;
}
int main()
{
	srand(time(NULL)),scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	while(clock()+t<4*CLOCKS_PER_SEC)
	{
		if(!t1)t1=clock();
		x=a[RND()],vec.clear();
		for(LL i=1;i*i<=x;++i)
			if(!(x%i))
			{
				cnt[vec.size()]=0,vec.push_back(i);
				if(i*i!=x)cnt[vec.size()]=0,vec.push_back(x/i); 
			}
		sort(vec.begin(),vec.end());
		for(int i=1;i<=n;++i)++cnt[lower_bound(vec.begin(),vec.end(),gcd(a[i],x))-vec.begin()];
		for(int i=0;i<vec.size();++i)
			for(int j=i+1;j<vec.size();++j)
				if(!(vec[j]%vec[i]))
					cnt[i]+=cnt[j];
		for(int i=vec.size()-1;~i;--i)
			if((cnt[i]<<1)>=n)
			{
				ans=max(ans,vec[i]);
				break;
			}
		if(!t)t=clock()-t1;
	}
	return 0&printf("%lld",ans);
}