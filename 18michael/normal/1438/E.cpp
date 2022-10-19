#include<cstdio>
#include<set>
#define Mx 29
#define LL long long
using namespace std;
int n;LL sum=0;
int lg[200002];
LL a[200002];
typedef pair<int,int> P;
set<P> s;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		for(int j=Mx;~j;--j)
			if(a[i]>>j)
			{
				lg[i]=j;
				break;
			}
	}
	for(int i=1;i<=n;++i)
	{
		sum=0;
		for(int j=i+1;j<n;++j)
		{
			sum+=a[j];
			if(sum>=(1<<(lg[i]+1)))break;
			if((a[i]^a[j+1])==sum)s.insert(P(i,j+1));
		}
	}
	for(int i=n;i;--i)
	{
		sum=0;
		for(int j=i-1;j>1;--j)
		{
			sum+=a[j];
			if(sum>=(1<<(lg[i]+1)))break;
			if((a[j-1]^a[i])==sum)s.insert(P(j-1,i));
		}
	}
	printf("%d",s.size());
	return 0;
}