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
int a,b,n;
int f[35005][35];
inline int pw(int a,int b)
{
	int ans=1;
	for(int i=1;i<=b;i++)ans*=a;
	return ans;
}
inline bool pd(int a,int b)
{
	long long tmp=1;
	for(int i=1;i<=b;i++)
	{
		tmp*=a;
		if(tmp>=n)return 1;
	}
	return 0;
}
int main()
{
	read(a),read(b),read(n);
	if(pd(a,b))
	{
		puts("Masha");
		return 0;
	}
	if(a==1&&pw(2,b)>=n)
	{
		puts("Missing");
		return 0;
	}
	for(int i=35000;i>=1;i--)
		for(int j=30;j>=1;j--)
		{
			if(pd(i,j))
			{
				f[i][j]=1;
				continue;
			}
			if(i*i>=n&&j==1)f[i][j]=!f[i+1][j];
			else f[i][j]=(!f[i+1][j])|(!f[i][j+1]);
		}
	if(f[a][b])puts("Masha");
	else puts("Stas");
	return 0;
}