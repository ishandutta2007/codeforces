#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string> 
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
inline void read(int&n)
{int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();n=x*f;}
int writingarray[20];
inline void write(int k)
{int num=0;if(k<0)putchar('-'),k=-k;if(!k)writingarray[++num]=0;while(k)writingarray[++num]=k%10,k/=10;while(num)putchar(writingarray[num--]+'0');puts("");}
/*----------------------------------------------------------------yf's header file---------------------------------------------------------------------------*/
long long d,k,a,b,t;
int main()
{
	scanf("%lld%lld%lld%lld%lld",&d,&k,&a,&b,&t);
	if(d<=k)
	{
		printf("%lld\n",a*d);
		return 0;
	}
	long long part=d/k+(d%k!=0);
	if(a*k+t<=b*k)
	{
		long long ans=(part-2)*(a*k+t);
		long long p=d-(part-1)*k;
		ans+=min(a*k+t+a*p,a*k+b*p);
		printf("%lld\n",ans);
		return 0;
	}
	long long ans=a*k+(d-k)*b;
	printf("%lld\n",ans);
	return 0;
}