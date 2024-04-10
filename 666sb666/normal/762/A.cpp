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
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
long long n,k,tot;
int main()
{
	scanf("%lld%lld",&n,&k);
	long long m=sqrt(n);
	for(long long i=1;i<=m;i++)if(n%i==0)
	{
		tot++;
		if(tot==k)return printf("%lld\n",i),0;
	}
	if(m*m==n)tot--;
	for(long long i=m;i>=1;i--)if(n%i==0)
	{
		tot++;
		if(tot==k)return printf("%lld\n",n/i),0;
	}
	puts("-1");
	return 0;
}