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
const int maxn=101;
int n,a[maxn],b[maxn],x,y;
int main()
{
	read(n),x=0,y=0;
	for(int i=1;i<=n;i++)read(a[i]),read(b[i]);
	for(int i=1;i<=n;i++)if(a[i]>b[i])x++;
	else if(a[i]<b[i])y++;
	if(x>y)puts("Mishka");
	else if(x<y)puts("Chris");
	else puts("Friendship is magic!^^");
	return 0;
}