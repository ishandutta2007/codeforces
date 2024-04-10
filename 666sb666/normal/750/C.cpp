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
const int N=2e5+5;
int n,a[N],b[N],now,mx=-1e9,mn=1e9;
bool flag=true;
int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),read(b[i]);
	for(int i=1;i<=n;i++)if(b[i]==2)flag=false;
	if(flag)return puts("Infinity"),0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)mx=max(mx,1900-now);
		else mn=min(mn,1899-now);
		now+=a[i];
	}
	if(mx>mn)return puts("Impossible"),0;
	for(int i=1;i<=n;i++)mn+=a[i];
	write(mn);
	return 0;
}