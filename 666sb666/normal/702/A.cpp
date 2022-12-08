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
/*----------------------------------------------------------------yf's header file---------------------------------------------------------------------------*/
const int maxn=100001;
int n,a[maxn];
int main()
{
	int ans=0;
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	int head=1;
	while(head<=n)
	{
		int tail=head;
		while(a[tail+1]>a[tail]&&tail<n)tail++;
		ans=max(ans,tail-head+1);
		head=tail+1;
	}
	write(ans);
	return 0;
}