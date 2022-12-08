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
int n;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
	read(n);
	if(n<=2)return write(n),0;
	if(n%2)return printf("%lld\n",(long long)n*(n-1)*(n-2)),0;
	long long ans=(long long)(n-1)*(n-2)*(n-3),tmp=(long long)n*(n-1);
	for(int i=n-2;i>=1;i--)
	{
		int g1=gcd(i,n),g2=gcd(i,n-1);
		ans=max(ans,tmp*i/g1/g2);
	}
	printf("%lld\n",ans);
	return 0;
}