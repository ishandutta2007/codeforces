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
const int N=3e5+5;
int x,y,z,m,a[N],b[N],c[N<<1],num1,num2,num,tot;
long long ans;
char s[10];
int main()
{
	read(x),read(y),read(z);
	read(m);
	while(m--)
	{
		int val;
		scanf("%d%s",&val,s);
		if(s[0]=='U')a[++num1]=val;else b[++num2]=val;
	}
	sort(a+1,a+num1+1);
	sort(b+1,b+num2+1);
	int p=min(x,num1),q=min(y,num2);
	for(int i=1;i<=p;i++)ans+=a[i],tot++;
	for(int i=1;i<=q;i++)ans+=b[i],tot++;
	for(int i=p+1;i<=num1;i++)c[++num]=a[i];
	for(int i=q+1;i<=num2;i++)c[++num]=b[i];
	sort(c+1,c+num+1);
	int r=min(z,num);
	for(int i=1;i<=r;i++)ans+=c[i],tot++;
	printf("%d %lld\n",tot,ans);
	return 0;
}