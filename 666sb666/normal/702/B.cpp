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
const int maxn=100001;
int n,a[maxn];
map<int,int>m;
/*----------------------------------------------------------------yf's header file---------------------------------------------------------------------------*/
int main()
{
	long long ans=0;
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),m[a[i]]++;
	int p=1;
	for(int i=1;i<=30;i++)
	{
		p*=2;
		for(int j=1;j<=n;j++)if(p>a[j])
		{
			ans+=(long long)m[p-a[j]];
			if(p==2*a[j])ans--;
		}
	}
	printf("%lld\n",ans/2);
	return 0;
}