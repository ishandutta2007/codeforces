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
const int N=1e5+5;
int n;
double a[N],b[N],f[N];
int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		b[i]=(b[i-1]+1)*a[i];
		f[i]=f[i-1]+(2*b[i-1]+1)*a[i];
	}
	printf("%.10lf\n",f[n]);
	return 0;
}