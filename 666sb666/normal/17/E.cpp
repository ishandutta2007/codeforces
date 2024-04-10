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
const int maxn=2000005,mod=51123987;
char s[maxn<<1];
int n,len=0,p[maxn<<1],start[maxn],finish[maxn],a[maxn],b[maxn];
int main()
{
	read(n);
	s[++len]='#';
	for(int i=1;i<=n;i++)
	{
		char ch=getchar();
		while(ch<'a'||ch>'z')ch=getchar();
		s[++len]=ch;
		s[++len]='#';
	}
	int mx=0,id=0;
	for(int i=1;s[i]!='\0';i++)
	{
		p[i]=mx>i?min(p[2*id-i],mx-i):1;
		while(s[i+p[i]]==s[i-p[i]]&&i+p[i]<=len)p[i]++;
		if(i+p[i]>mx)mx=i+p[i],id=i;
	}
	for(int i=1;i<=len;i++)
	{
		int id=i/2,q=p[i]/2;
		a[id-q+1]++,a[id+1]--;
	}
	for(int i=1;i<=n;i++)start[i]=start[i-1]+a[i];
	for(int i=1;i<=len;i++)
	{
		int id=(i+1)/2,q=p[i]/2;
		b[id]++,b[id+q]--;
	}
	for(int i=1;i<=n;i++)finish[i]=finish[i-1]+b[i];
	long long a=0,b=0,ans=0,tmp=0;
	for(int i=1;i<=n;i++)a+=start[i];
	b=a-1;
	if(a%2==0)a/=2;
	else b/=2;
	ans=(a%mod)*(b%mod)%mod;
	for(int i=1;i<=n;i++)
	{
		ans=(long long)(ans-(start[i]*tmp)%mod),tmp=(long long)(tmp+finish[i])%mod;
		if(ans<0)ans+=mod;
	}
	printf("%lld\n",ans);
	return 0;
}