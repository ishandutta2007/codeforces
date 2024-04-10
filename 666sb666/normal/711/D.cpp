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
/*-----------------------------------------------------header file----------------------------------------------------------------*/
const int maxn=2e5+1,mod=1e9+7;
int n,a[maxn],pw[maxn],num[maxn],tot,key;
int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*2%mod;
	long long ans=1;
	for(int i=1;i<=n;i++)if(!num[i])
	{
		int j=i;
		while(!num[j])
		{
			num[j]=++key;
			j=a[j];
			if(num[j]>=num[i])tot+=key-num[j]+1,ans=ans*(pw[key-num[j]+1]-2)%mod;
		}
	}
	ans=ans*pw[n-tot]%mod;
	printf("%I64d\n",ans);
	return 0;
}