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
int n,x,y;
string s;
int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		cin>>x>>s;
		if(!y&&s!="South")return puts("NO"),0;
		if(y==20000&&s!="North")return puts("NO"),0;
		if(s=="North"&&x>y)return puts("NO"),0;
		else if(s=="South"&&x+y>20000)return puts("NO"),0;
		if(s=="North")y-=x;
		else if(s=="South")y+=x;
	}
	if(y)puts("NO");
	else puts("YES");
	return 0;
}